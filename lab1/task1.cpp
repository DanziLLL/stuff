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
    while (nextname.compare("000")!=0){
	cout << endl << "Input friend's name: ";
	cin >> nextname;
	if (nextname.compare("000")==0){
	    break;
	    }
	friendslist << nextname;
	cout << "Input friend's age: ";
	cin >> nextage;
	friendslist << "\t" << nextage << endl;
	}
    return 0;
}