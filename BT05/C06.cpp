#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while(a!= 0 && b!= 0) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

int main()
{
    int a, b;
    if (gcd(a, b) == 1) cout << "YES";
    else cout << "NO";
    return 0;
}