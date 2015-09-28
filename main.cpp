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
    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}