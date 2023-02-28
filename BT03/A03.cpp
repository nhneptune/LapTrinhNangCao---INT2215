#include <iostream>

using namespace std;

int main()
{
    // Phần a
    char daytaba1[2][12] = {
        {31,28,31,30,31,30,31,31,30,31,30,31},
        {31,29,31,30,31,30,31,31,30,31,30,31}
    };  

    char daytaba2[2][12] = {
        31,28,31,30,31,30,31,31,30,31,30,31,
        31,29,31,30,31,30,31,31,30,31,30,31
    };  

    for (int i = 0 ; i < 2; i++){
        for (int j = 0; j < 12; j++){
            cout << daytaba1[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 12; j++){
            cout << daytaba2[i][j] << " ";
        }
        cout << endl;
    }

    // Phần b
    char daytabb1[2][12] = {
        {31,28,31,30,31,30},
        {31,29,31,30,31,30,31,31}
    };  

    char daytabb2[2][12] = {
        31,28,31,30,31,30,
        31,29,31,30,31,30,31,31
    };

    for (int i = 0 ; i < 2; i++){
        for (int j = 0; j < 12; j++){
            cout << daytabb1[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 12; j++){
            cout << daytabb2[i][j] << " ";
        }
        cout << endl;
    }

    // Phần c
    char daytabc1[][12] = {
        {31,28,31,30,31,30,31,31,30,31,30,31},
        {31,29,31,30,31,30,31,31,30,31,30,31}
    };  

    // char daytabc2[2][] = {
    //     31,28,31,30,31,30,31,31,30,31,30,31,
    //     31,29,31,30,31,30,31,31,30,31,30,31
    // };  lỗi

    // char daytabc3[][] = {
    //     31,28,31,30,31,30,31,31,30,31,30,31,
    //     31,29,31,30,31,30,31,31,30,31,30,31
    // };  lỗi

    for (int i = 0 ; i < 2; i++){
        for (int j = 0; j < 12; j++){
            cout << daytabc1[i][j] << " ";
        }
        cout << endl;
    }

    // for (int i = 0; i < 2; i++){
    //     for (int j = 0; j < 12; j++){
    //         cout << daytabc2[i][j] << " ";
    //     }
    //     cout << endl;
    // } lỗi

    // for (int i = 0; i < 2; i++){
    //     for (int j = 0; j < 12; j++){
    //         cout << daytabc3[i][j] << " ";
    //     }
    //     cout << endl;
    // } lỗi
    
    return 0;
}