#include <iostream>
#include <cstdlib>

using namespace std;

template <class Array>
class IntegerArray {
private:
    int _size;
    Array *pointer;
public:
    IntegerArray <Array> () {
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

    IntegerArray <Array> (int size) {
        _size = size;
        try {
            if (_size > 1000000) {
                string err("Overflow!");
                throw err;
            }
        }
        catch (string err){
            cout << err << endl << endl;
        }
        pointer = new Array[size];
        for (int i = 0; i < size; i++) {
            pointer[i] = rand() % 100;
        }
    }

    IntegerArray <Array> (int size, Array *arr) {
        _size = size;
        pointer = new int[size];
        for (int i = 0; i < size; i++) {
            pointer[i] = arr[i];
        }
    }

    IntegerArray <Array> (const IntegerArray &object) {
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

    void MinMax() {
        int min = 101, max = 0;
        for (int i = 0; i < _size; i++) {
            if (pointer[i] < min) {
                min = pointer[i];
            }
            if (pointer[i] > max) {
                max = pointer[i];
            }
            string err("Error in MinMax method");
            try {
                if (i>=_size){
                    throw err;
                }
            }
            catch (string err){
                cout << err << endl;
            }
        }
        cout << "Min: " << min << endl;
        cout << "Max: " << max << endl << endl;
    }

    void Sort(){
        int i = 0;
        Array key;
        for(int j = 1; j < _size; j++)    // Start with 1 (not 0)
        {
            key = pointer[j];
            for(i = j - 1; (i >= 0) && (pointer[i] < key); i--)   // Smaller values move up
            {
                pointer[i+1] = pointer[i];
            }
            pointer[i+1] = key;    //Put key into its proper location
        }
    }

    IntegerArray &operator= (IntegerArray &original){
        delete pointer;
        _size = original._size;
        pointer = new Array [_size];
        for (int i = 0; i < _size; i++) {
            pointer[i] = original.pointer[i];
        }
        return *this;
    }

    Array &operator[](int i){
        try {
            if (i >= _size) {
                string err("Unreachable element!");
                throw err;
            }
        }
        catch (string err){
            cout << err << endl;
        }
        return pointer[i];
    }

    bool operator==(IntegerArray<Array> &arr2){
        if (_size == arr2._size) {
            for (int i = 0; i < _size; i++) {
                if (pointer[i] != arr2.pointer[i]){
                    return false;
                }
            }
            return true;
        }
    }

    bool operator!=(IntegerArray<Array> &arr2){
        if (_size == arr2._size) {
            for (int i = 0; i < _size; i++) {
                if (pointer[i] != arr2.pointer[i]){
                    return true;
                }
            }
            return false;
        }
    }
};

int main() {
    cout << "Testing exception in resizable constructor..." << endl;
    IntegerArray<int> overflow_test(10000000);
    cout << "Creating integer-type object..." << endl;
    IntegerArray<int> int_test;
    IntegerArray<int> int_test_copy(int_test);
    int_test.Sort();
    int_test.PrintArray();
    int_test.MinMax();
    cout << "Creating long-type object..." << endl;
    IntegerArray<long> long_test;
    long_test.Sort();
    long_test.PrintArray();
    long_test.MinMax();
    cout << "Creating double-type object..." << endl;
    IntegerArray<double> double_test;
    double_test.Sort();
    double_test.PrintArray();
    double_test.MinMax();
    cout << "Creating short-type object..." << endl;
    IntegerArray<short> short_test;
    short_test.Sort();
    short_test.PrintArray();
    short_test.MinMax();
    cout << "Overloading \"=\"..." << endl;
    IntegerArray<short> short_test_copy;
    short_test_copy = short_test;
    short_test_copy.PrintArray();
    cout << endl << "Overloading \"int_test[5]\" and testing out-of-bounds exception..." << endl;
    int_test.PrintArray();
    cout << "int_test[5] = " << int_test[5] << endl;
    cout << "int_test[1000]: ";
    int_test[1000];
    cout << endl <<"Overloading \"==\"..." << endl;
    if (bool check = short_test==short_test_copy){
        cout << "Comparing equal arrays: ";
        cout << check << endl;
    }
    if (!(int_test==int_test_copy)){
        cout << "Comparing different arrays: ";
        bool check = (int_test==int_test_copy);
        cout << check << endl << endl;
    }
    cout << "Overloading \"!=\"..." << endl;
    if (int_test!=int_test_copy){
        cout << "Comparing different arrays: ";
        bool check = (int_test!=int_test_copy);
        cout << check << endl;
    }
    if (!(short_test!=short_test_copy)){
        bool check = (short_test!=short_test_copy);
        cout << "Comparing equal arrays: ";
        cout << check << endl << endl;
    }

    return 0;
}