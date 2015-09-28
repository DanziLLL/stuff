#include <iostream>
#include <cstdlib>

using namespace std;

class IntegerArray
{
private:
    int _size;
    int *pointer;
public:
    IntegerArray(){
        int size = 10;
        _size = size;
        pointer = new int [size];
        for (int i = 0; i < size; i++) {
            pointer[i] = rand() % 100;
        }
    }
    ~IntegerArray(){
        cout << "Object destroyed!" << endl;
    }
    IntegerArray(int size){
        _size = size;
        pointer = new int [size];
        for (int i = 0; i < size; i++) {
            pointer[i] = rand() % 100;
        }
    }
    IntegerArray(const IntegerArray &object){
        _size = object._size;
        pointer = new int [_size];
        for (int i = 0; i < _size; i++) {
            pointer[i] = object.pointer[i];
        }
    }
    void PrintArray(){
        for (int i = 0; i < _size; i++) {
            cout << pointer[i] << "\t";
        }
        cout << endl;
    }
    void MinMax(){
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
    }
    void CopyCheck(){
        for (int i = 0; i < _size; i++) {
            pointer[i]++;
        }
    }
};

int main() {
    IntegerArray test_default;
    IntegerArray test_resizable(15);
    cout << "===WORKING WITH DEFAULT CONSTRUCTOR===" << endl;
    test_default.PrintArray();
    test_default.MinMax();
    cout << "===WORKING WITH RESIZABLE CONSTRUCTOR===" << endl;
    test_resizable.PrintArray();
    test_resizable.MinMax();
    cout << "===WORKING WITH RESIZABLE CONSTRUCTOR'S OBJECT COPY===" << endl;
    IntegerArray copy(test_resizable);
    copy.CopyCheck();
    copy.PrintArray();
    copy.MinMax();
    cout << "===RESIZABLE OBJECT CHECK===" << endl;
    test_resizable.PrintArray();
    return 0;
}