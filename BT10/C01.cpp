#include <iostream>

using namespace std;

struct String{
    int n;
    char *s;
    String (const char *s){
        n = strlen(s);
        this->s = new char[n + 1];
        strcpy(this->s, s);
    }
};


