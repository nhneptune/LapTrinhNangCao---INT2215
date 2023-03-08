#include <iostream>

using namespace std;    

int factorial(int n) {
    cout << &n << endl;
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int square(int &n) {
    cout << &n << endl;
    return n * n;
}

int main()
{
    int a = 5, b = 6;
    cout << &a << " " << factorial(a) << endl; //địa chỉ của đối số và tham trị khác nhau
    cout <<  &b << " " << square(b) << endl; //địa chỉ của đối số và tham biến giống nhau
    return 0;
}