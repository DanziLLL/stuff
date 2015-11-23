#define pr << a << "+" << b << "=";
#define NOTTEMPLATE
#include <iostream>

using namespace std;

#ifndef NOTTEMPLATE
template <typename Type>
    int smth(int a, Type b){
        cout << "Int-templated pair acquired: " pr;
        return a+b;
    }
#endif

#ifdef NOTTEMPLATE
int smth(int a, int b);
int smth(int a, float b);
int smth(int a, char b);
int smth(int a, long b);
int smth(int a, double b);
#endif

int main(){
    int dummy1 = 10;
    float dummy2 = 13.0;
    char dummy3 = 'd';
    long dummy4 = 20.0;
    double dummy5 = 31.0;
    cout << smth(dummy1, dummy1) << endl;
    cout << smth(dummy1, dummy2) << endl;
    cout << smth(dummy1, dummy3) << endl;
    cout << smth(dummy1, dummy4) << endl;
    cout << smth(dummy1, dummy5) << endl;
    return 0;
}

#ifdef NOTTEMPLATE
int smth(int a, int b){
    cout << "Int-int pair acquired: " pr;
    return a+b;
}
int smth(int a, float b){
    cout << "Int-float pair acquired: " pr;
    return a+b;
}
int smth(int a, char b){
    cout << "Int-char pair acquired: " pr;
    return a+b;
}
int smth(int a, long b){
    cout << "Int-long pair acquired: " pr;
    return a+b;
}

int smth(int a, double b){
    cout << "Int-double pair acquired: " pr;
    return a+b;
}
#endif