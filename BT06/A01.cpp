#include <iostream>

using namespace std;

void sort(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << &a << " " << &a[0] << endl;
}

int main()
{
    int a[10] = {1, 7, 3, 4, 8, 6, 2, 5, 9, 10};
    cout << &a << " " << &a[0] << endl;
    sort(a, 10);
    return 0;
}
// Mảng truyền vào hàm theo cơ chế pass by value, nên địa chỉ của mảng trong hàm sort() sẽ khác với địa chỉ của mảng trong hàm main().
// Phần tử đầu tiên của mảng trong hàm sort() có địa chỉ giống với địa chỉ của mảng trong hàm main().
