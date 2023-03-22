#include <iostream>

using namespace std;

struct Point {
    int x, y;

    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Point p1, p2;
    p1.x = 1;
    p1.y = 2;
    p2.x = 3;
    p2.y = 4;
    p1.print();
    p2.print();
    return 0;
}