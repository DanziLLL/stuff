#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main(){
    fstream list;
    list.open("1.txt", fstream::in | fstream::out);
    string nextword;
    set<string> words;
    while (!list.eof()){
        list >> nextword;
        words.insert(nextword);
    }
    int set_size = words.size();
    cout << set_size;
    return 0;
}