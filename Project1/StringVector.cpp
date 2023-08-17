#include <iostream>
#include <string>

class StringVector {
private:
    std::string* arr;
    int capacity;
    int size;

public:
    StringVector() : arr(nullptr), capacity(0), size(0) {}

    ~StringVector() {
        delete[] arr;
    }

    void push_back(const std::string& value) {
        if (size >= capacity) {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            std::string* newArr = new std::string[newCapacity];
            for (int i = 0; i < size; ++i) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        }
        arr[size++] = value;
    }

    std::string at(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        throw std::out_of_range("Index out of bounds");
    }

    int getSize() {
        return size;
    }
};

int main() {
    StringVector stringVec;
    stringVec.push_back("Hello");
    stringVec.push_back("World");
    stringVec.push_back("!");

    std::cout << "Vector size: " << stringVec.getSize() << std::endl;

    try {
        std::cout << "Element at index 1: " << stringVec.at(1) << std::endl;
        std::cout << "Element at index 5: " << stringVec.at(5) << std::endl;  // This will throw an exception
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}