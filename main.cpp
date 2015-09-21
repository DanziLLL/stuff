#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ofstream friendslist;
    cout << "Input some friends, if there's no more - type \"exit\"" << endl;
    friendslist.open("list.txt");
    friendslist.close();
    fstream list;
    list.open("list.txt", fstream::in | fstream::out);
    string nextname = "111";
    string choice = "null";
    int nextage, i, blacklisted=0, total = 0;
    while (nextname.compare("exit") != 0) {
        cout << endl << "Input friend's name: ";
        cin >> nextname;
        if (nextname.compare("exit") == 0) {
            break;
        }
        total++;
        list << nextname;
        cout << "Input friend's age: ";
        cin >> nextage;
        list << "\t" << nextage << endl;
    }
    cout << "Do you want to generate blacklist? (y/n)" << endl;
    cin >> choice;
    ios::pos_type pos = 0;
    if (choice.compare("y") == 0) {
	list.seekg(0, list.end);
	list << "===BLACKLIST===" << endl;
	list.seekg(0 ,list.beg);
	for (i=0; i < total; i++){
	    list >> nextname;
	    list >> nextage;
	    pos = list.tellg();
	    if (nextage < 18) {
		    list.seekp(0, list.end);
		    list << nextname << "\t";
		    list << nextage << endl;
		    list.seekg(pos, list.beg);
		    blacklisted++;
	        }
	    }
    }
    list.seekp(0, list.end);
    list << "Total: " << total << endl;
    list << "Blacklisted: " << blacklisted;
    list.close();
    return 0;
}
