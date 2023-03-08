#include <iostream>
#include <stdlib.h>
using namespace std;

int random(int n){
    int x = rand();
    while (x >= n) x = rand();
    return x;
}

int main()
{
    int n;
    cin >> n
    cout << random(n);
    return 0;
}