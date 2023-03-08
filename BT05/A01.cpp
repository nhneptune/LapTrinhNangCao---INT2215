#include <iostream>

using namespace std;

int main()
{
    int c;
    int a[10];
    char b[10];
    int d;
    cout << &a[0] << " " << &a[1] << " " << &a[2] << endl;// mỗi địa chỉ cách nhau 4 byte
    cout << (void*)&b[0] << " " << (void*)&b[1] << " " << (void*)&b[2] << endl;// mỗi địa chỉ cách nhau 1 byte

    cout << &c << " " << &d << endl;// có vị trí tương đối ngẫu nhiên
    return 0;
}