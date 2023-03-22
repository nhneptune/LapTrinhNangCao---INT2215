#include <iostream>

using namespace std;

struct Point {
    int x, y;
};

struct line {
    Point p1, p2;
    int arr[10];
};

int main()
{
    line l;
    l.p1.x = 1;
    l.p1.y = 2;
    l.p2.x = 3;
    l.p2.y = 4;
    cout << &l << endl;
    cout << &l.p1 << endl;
    cout << &l.p2 << endl;
    cout << &l.arr << endl;
    return 0;
}