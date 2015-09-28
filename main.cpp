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
    void PrintArray(){
        for (int i = 0; i < _size; i++) {
            cout << pointer[i] << endl;
        }
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
};

int main() {
    IntegerArray test(15);
    test.PrintArray();
    test.MinMax();
    return 0;
}