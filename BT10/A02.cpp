#include <iostream>

using namespace std;

struct point{
    int x, y;    
};

void address_pbv(point p){
    cout << &p << endl;
}

void address_pbr(point &p){
    cout << &p << endl;
}

int main()
{
    point p;
    p.x = 1;
    p.y = 2;
    cout << &p << endl;
    address_pbv(p);
    address_pbr(p);
    return 0;
}