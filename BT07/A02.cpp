#include <iostream>

using namespace std;

int f(int a[])
{
    return sizeof(a);
}

int main()
{
    int a[10];
    cout << sizeof(a) << endl;
    cout << f(a) << endl;
    return 0;
}