#include <iostream>

using namespace std;

int BinarySearch(int x, int* a, int left, int right)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (x == a[mid]) return mid;
        if (x < a[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}   

int main()
{
    int n = 5;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout << BinarySearch(x, a, 0, n - 1) << endl;
    return 0;
}