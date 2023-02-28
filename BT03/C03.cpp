#include <iostream>

using namespace std;

bool soDoiGuong(int n)
{
    int m = n;
    int s = 0;
    if (n % 10 != 1) return false;
    while (m > 0)
    {
        s = s * 10 + m % 10;
        m /= 10;
    }
    return s == n;
}

int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (soDoiGuong(i))
            count++;
    
    cout << count;
    return 0;
}