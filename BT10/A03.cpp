#include <iostream>

using namespace std;

struct Point {
    int x, y; 
};

Point mid_point(const Point& p1, const Point& p2){
    Point p;
    p.x = (p1.x + p2.x) / 2;
    p.y = (p1.y + p2.y) / 2;
    return p;
}

int main()
{
    Point p1, p2;
    p1.x = 1;
    p1.y = 2;
    p2.x = 3;
    p2.y = 4;
    Point p = mid_point(p1, p2);
    cout << "(" << p.x << ", " << p.y << ")" << endl;
    return 0;
}