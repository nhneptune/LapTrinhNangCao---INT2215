#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x1, x2, y1, y2;
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;

    cout << sqrt((x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2));

    return 0;
}