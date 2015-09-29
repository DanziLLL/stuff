#include <iostream>
#include <cstdlib>

using namespace std;

class IntegerArray
{
private:
    int _size;
    int *pointer;
    static int count;
public:
    IntegerArray(){
        int size = 10;
        _size = size;
        pointer = new int [size];
        for (int i = 0; i < size; i++) {
            pointer[i] = rand() % 100;
        }
        count++;
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
        count++;
    }
    IntegerArray(int size, int *arr){
        _size = size;
        pointer = new int [size];
        for (int i = 0; i < size; i++) {
            pointer[i] = arr[i];
        }
        count++;
    }
    IntegerArray(const IntegerArray &object){
        _size = object._size;
        pointer = new int [_size];
        for (int i = 0; i < _size; i++) {
            pointer[i] = object.pointer[i];
        }
        count++;
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
    void ObjectsCounter(){
        cout << endl << "Total objects: " << count << endl;
    }
};
int IntegerArray::count = 0;
int main() {
    int size = 13;
    int arr[size] = {3,2,5,1,2,5,7,4,8,5,7,2,5};
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
    IntegerArray test_onemore(size, arr);
    cout << "===WORKING WITH ONE MORE CONSTRUCTOR===" << endl;
    test_onemore.PrintArray();
    test_onemore.MinMax();
    copy.ObjectsCounter();
    return 0;
}