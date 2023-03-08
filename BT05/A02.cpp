#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    cout << n << " " << &n << endl;
    return n * factorial(n - 1);
}

int main()
{
    int n = 5;
    cout << factorial(n) << endl; //kích thước 1 stack frame cho hàm factorial là 48 byte
    return 0;
}
