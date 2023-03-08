#include <iostream>
#include <ctime>

using namespace std;

int RecursiveBinarySearch(int x, int a[], int left, int right) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (x == a[mid]) return mid;
    if (x < a[mid]) return RecursiveBinarySearch(x, a, left, mid - 1);
    return RecursiveBinarySearch(x, a, mid + 1, right);
}

int LoopBinarySearch(int x, int a[], int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (x == a[mid]) return mid;
        if (x < a[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}


int main()
{
    clock_t begin = clock();
    int n = 5;
    int a[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
    
    cout << RecursiveBinarySearch(120, a, 0, 99) << endl;
    cout << RecursiveBinarySearch(1, a, 0, 99) << endl;
    cout << RecursiveBinarySearch(100, a, 0, 99) << endl;
    cout << RecursiveBinarySearch(57, a, 0, 99) << endl;
    
    cout << LoopBinarySearch(120, a, 0, 99) << endl;
    cout << LoopBinarySearch(1, a, 0, 99) << endl;
    cout << LoopBinarySearch(100, a, 0, 99) << endl;
    cout << LoopBinarySearch(57, a, 0, 99) << endl;
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Time:" << elapsed_secs << endl;
    return 0;
}