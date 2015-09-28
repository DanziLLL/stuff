#include <iostream>

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
            pointer[i] = i;
        }
    }
    void PrintArray(){
        for (int i = 0; i < 10; i++) {
            cout << pointer[i] << endl;
        }
    }
};

int main() {
    IntegerArray test;
    test.PrintArray();
    return 0;
}