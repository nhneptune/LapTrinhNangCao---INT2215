#include <iostream>

using namespace std;

long fibonacci(int n){
    long fibo[n + 1];
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    return fibo[n];
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
//đến tầng 49 bị tràn bộ nhớ