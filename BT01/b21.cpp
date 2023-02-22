#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, s;
    cin >> a;
    cin >> b;
    cin >> c;

    s = (a + b + c)/2;
    cout << sqrt(s*(s - a)*(s - b)*(s - c));

    return 0;
}