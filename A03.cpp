#include <iostream>

using namespace std;

void taoDay(int arr[], int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int value;
    cin >> value;
    int size;
    cin >> size;
    int *arr = new int [size];
    taoDay(arr, size);

    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int right = size - 1, left = 0, mid = (right + left) / 2;
    while(left <= right){
        if (arr[mid] == value){
            cout << mid;
            return 0;
        }
        else if (arr[mid] > value){
            right = mid - 1;
            mid = (right + left) / 2;
        }
        else {
            left = mid + 1;
            mid = (right + left) / 2;
        }
    }

    cout << "Khong tim thay";
    
    return 0;
}