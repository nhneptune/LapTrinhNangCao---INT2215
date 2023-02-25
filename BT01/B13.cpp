#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x, y;
    cin >> x;
    cin >> y;

    double distance = sqrt(x*x + y*y);
    cout << distance;

    return 0;
}
