#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void RandomArray(int arr[], int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 101;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    // int n;
    // cin >> n;
    // if (n < 0 && n > 100){
    //     cout << "Nhap lai n";
    //     return 0;
    // }
    
    // Phần d
    cout << "Phan d:" << endl;
    int arrd[100];
    RandomArray(arrd, 100);

    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (arrd[j] > arrd[j + 1]){
                int temp = arrd[j];
                arrd[j] = arrd[j+ 1];
                arrd[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 100; i++){
        cout << arrd[i] << " ";
    }
    cout << endl;
    
    // Phần a, b, c, e, f
    cout << "Phan a, b, c, e, f:" << endl;
    ifstream file("inputA01.txt");
    if (file.is_open()){
        while(!file.eof()){
            int n;
            file >> n;
            int arr[n];
            for (int i = 0; i < n; i++){
                file >> arr[i];
            }

            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (arr[j] > arr[j + 1]){
                        int temp = arr[j];
                        arr[j] = arr[j+ 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            for (int i = 0; i < n; i++){
                cout << arr[i] << " ";
            }  
            cout << endl;
        }      
    }
    return 0;
}