#include <iostream>
#include <ctime>

using namespace std;

long F(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return F(n-1) + F(n-2);
}

long G(int n) {
    int a = 0, b = 1, c;
    if (n == 0) return a;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main()
{   
    int n;
    cin >> n;
    clock_t start1, end1, start2, end2;
    start1 = clock();
    cout << F(n) << endl;
    end1 = clock();
    cout << "Time: " << (double)(end1 - start1)/CLOCKS_PER_SEC << endl;

    start2 = clock();
    cout << G(n) << endl;
    end2 = clock();
    cout << "Time: " << (double)(end2 - start2)/CLOCKS_PER_SEC << endl;
    return 0;
}
//Vòng lặp nhanh hơn đệ quy