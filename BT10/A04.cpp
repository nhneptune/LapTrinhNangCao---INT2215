#include <iostream>

using namespace std;

struct Point {
    int x, y;
};

int main(){
    Point p;
    p.x = 1;
    p.y = 2;
    cout << &p << endl;
    cout << &p.x << endl;
    cout << &p.y << endl;
    return 0;
}
// Trường x có cùng địa chị với biến p, trường y có địa chỉ cách biến p 4 byte.