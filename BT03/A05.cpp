#include <iostream>

using namespace std;

int main()
{
    int arr[30];
    srand(time(NULL));
    for (int i = 0; i < 30; i++)
        arr[i] = rand() % 100;
    for (int i = 0; i < 30; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 30; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j+ 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 30; i++)
        cout << arr[i] << " ";
    return 0;
}