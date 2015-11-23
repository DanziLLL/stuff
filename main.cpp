#include <iostream>
#include <fstream>
#include <set>
#include <bits/stl_vector.h>

using namespace std;

int main(){
    fstream list;
    list.open("1.txt",fstream::in | fstream::out);
    string nextword;
    set<string> words;
    while (!list.eof()){
        list >> nextword;
        words.insert(nextword);
    }
    list.close();
    vector<string> secondfile;
    fstream text;
    text.open("2.txt", fstream::in | fstream::out);
    while (!text.eof()){
        text >> nextword;
        secondfile.insert(secondfile.end(), nextword);
    }
    cout << secondfile.size();
    return 0;
}