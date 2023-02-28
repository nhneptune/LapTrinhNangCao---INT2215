#include <iostream>

using namespace std;

int main()
{
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    a[-1] = 11;
    a[10] = 12;
    a[11] = 13;
    cout << a[-1] << endl;
    cout << a[10] << endl;
    cout << a[11] << endl;

    return 0;
}