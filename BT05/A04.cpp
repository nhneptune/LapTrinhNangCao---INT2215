#include <iostream>

using namespace std;

void sort(int a[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void uppercase(string s){
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
    }
}

int main()
{
    int a[] = { 1, 3, 2, 5, 4 };
    sort(a, 5);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    //mảng được truyền theo cơ chế pass by reference
    string s = "hello";
    uppercase(s);
    cout << s << endl;
    return 0;
    // string được truyền theo cơ chế pass by value
}