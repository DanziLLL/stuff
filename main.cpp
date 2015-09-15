#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;
int main() {
    ofstream friendslist;
    cout << "Input some friends, if there's no more - type \"exit\"" << endl;
    friendslist.open("list.txt");
    string nextname = "111";
    int nextage, normal, blacklisted, total = 0;
    while (nextname.compare("exit") != 0) {
        cout << endl << "Input friend's name: ";
        cin >> nextname;
        if (nextname.compare("exit") == 0) {
            break;
        }
        total++;
        friendslist << nextname;
        cout << "Input friend's age: ";
        cin >> nextage;
        friendslist << "\t" << nextage << endl;
    }
    friendslist.close();
    cout << "Do you want to generate blacklist? (y/n)" << endl;
    cin >> nextname;
    if (nextname.compare("y" == 0)) {
        fstream blacklist("test.txt", fstream::in | fstream::out);
        struct entry {
            string name;
            int age;
        };
        int i = 0;
        char nextline[30];
        entry allentries[total];
        while (!blacklist.eof()){
    }
        friendslist.close();
        return 0;
    }
}