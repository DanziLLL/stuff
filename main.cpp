#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;
int main()
{
    ofstream friendslist;
    cout << "Input some friends, if there's no more - type \"exit\"" << endl;
    friendslist.open("list.txt");
    string nextname = "111";
    int nextage;
    while (nextname.compare("exit")!=0){
        cout << endl << "Input friend's name: ";
        cin >> nextname;
        if (nextname.compare("exit")==0){
            break;
        }
        friendslist << nextname;
        cout << "Input friend's age: ";
        cin >> nextage;
        friendslist << "\t" << nextage << endl;
    }
    cout << "Do you want to generate blacklist? (y/n)" << endl;
    cin >> nextname;
    if (nextname.compare("y"==0)){
        ifstream blacklist;
        blacklist.open("list.txt");
        while (!blacklist.eof()) {

        }
    }
    friendslist.close();
    return 0;
}