#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main(){
    fstream list;
    list.open("1.txt",fstream::in | fstream::out);
    string nextword;
    char restricted[12] = {'(',')','.', ',', ';', ':', '!', '?', '/', '\\', '"', '$'};
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
        for (int i = 0; i < 12; i++) {
            if(nextword.find(*(restricted+i)) != string::npos){
                nextword = nextword.erase(nextword.find(*(restricted+i)), 1);
            }
        }
        if ((nextword.length() > 3)&&(words.count(nextword) == 0)) {
            secondfile.push_back(nextword);
        }
    }
    map<string,int> statlist;
    for (int k = 0; k < (int)secondfile.size(); k++){
        nextword = secondfile[k];
        statlist.insert(pair<string,int>(nextword, 0));
        for (int l = 0; l < (int)secondfile.size(); l++) {
            if (nextword == secondfile[l]){
                statlist[nextword]++;
                secondfile[l].erase();
            }
        }
        if (statlist[nextword] <= 1) {
            statlist.erase(nextword);
        }
    }
    cout << secondfile.size();
    ofstream generate;
    generate.open("3.txt");
    generate.close();
    fstream container;
    container.open("3.txt", fstream::in | fstream::out);
    map<string,int>::iterator it;
    for ( it = statlist.begin(); it != statlist.end(); ++it) {
        container << (*it).first << '\t' << (*it).second << endl;
    }

    return 0;
}