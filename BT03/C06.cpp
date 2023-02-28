#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int magicArray[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            magicArray[i][j] = 0;
        }
    }
    
    magicArray[0][n / 2] = 1;
    int value = 2;
    int hang = 0, cot = n / 2;

    while(value <= n * n){
        if (hang - 1 < 0 && cot + 1 >= n){
            hang++;
        }
        else if (hang - 1 < 0){
            hang = n - 1;
            cot++;
        }
        else if (cot + 1 >= n){
            cot = 0;
            hang--;
        }
        else if (magicArray[hang - 1][cot + 1] != 0){
            hang++;
        }
        else{
            hang--;
            cot++;
        }
        magicArray[hang][cot] = value;
        value++;
    }

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << magicArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}