#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#define CHARS ||(nextword[nextword.length()-1]==',')||(nextword[nextword.length()-1]=='!')||(nextword[nextword.length()-1]==':')||(nextword[nextword.length()-1]=='?')||(nextword[nextword.length()-1]==';')

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
        if (words.count(nextword)==0){
	    secondfile.insert(secondfile.end(), nextword);
	}
    }
    cout << secondfile.size();
    ofstream generate;
    generate.open("3.txt");
    generate.close();
    fstream out;
    out.open("3.txt", fstream::in | fstream::out);
    for (int i = 0; i < secondfile.size(); i++){
        nextword = secondfile[i];
        if ((nextword[nextword.length()-1]=='.'CHARS));{
            nextword.erase(nextword.length()-1);
        }
        if (words.count(nextword)!=0){
            out << nextword << '\n';
            secondfile.erase(secondfile.begin()+i);
        }
    }
    cout << secondfile.size();
    return 0;
}