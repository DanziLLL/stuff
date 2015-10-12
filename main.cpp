#include <iostream>
#include <cstdlib>

using namespace std;

template <class Array>
class IntegerArray {
private:
    int _size;
    Array *pointer;
public:
    IntegerArray() {
        int size = 10;
        _size = size;
        pointer = new Array[size];
        for (int i = 0; i < size; i++) {
            pointer[i] = rand() % 100;
        }
    }

    ~IntegerArray() {
        cout << "Object destroyed!" << endl;
    }

    IntegerArray(int size) {
        _size = size;
        pointer = new Array[size];
        for (int i = 0; i < size; i++) {
            pointer[i] = rand() % 100;
        }
    }

    IntegerArray(int size, Array *arr) {
        _size = size;
        pointer = new int[size];
        for (int i = 0; i < size; i++) {
            pointer[i] = arr[i];
        }
    }

    IntegerArray(const IntegerArray &object) {
        _size = object._size;
        pointer = new Array[_size];
        for (int i = 0; i < _size; i++) {
            pointer[i] = object.pointer[i];
        }
    }

    void PrintArray() {
        for (int i = 0; i < _size; i++) {
            cout << pointer[i] << "\t";
        }
        cout << endl;
    }

/*    void MinMax() {
        int min = 101, max = 0;
        for (int i = 0; i < _size; i++) {
            if (pointer[i] < min) {
                min = pointer[i];
            }
            if (pointer[i] > max) {
                max = pointer[i];
            }
        }
        cout << "Min: " << min << endl;
        cout << "Max: " << max << endl;
    }*/
};
int main() {
    IntegerArray<int> int_test;
    int_test.PrintArray();
    IntegerArray<char> char_test;
    char_test.PrintArray();
    return 0;
}