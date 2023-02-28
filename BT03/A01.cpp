#include <iostream>

using namespace std;

int a_out[5];
// int b_out1[3] = {1, 2, 3, 4}; lỗi
int b_out2[5] = {1, 2, 3, 4};
int c_out[] = {1, 2, 3, 4};

int main()
{
    int a_in[5];
//    int b_in1[3] = {1, 2, 3, 4}; lỗi
    int b_in2[5] = {1, 2, 3, 4};
    int c_in[] = {1, 2, 3, 4};
    
    // Phần a
    for (int i = 0; i < 5; i++)
        cout << a_out[i] << " ";
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << a_in[i] << " ";
    cout << endl;

    // phần b
    for (int i = 0; i < 5; i++)
        cout << b_out2[i] << " ";
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << b_in2[i] << " ";
    cout << endl;

    // phần c
    for (int i = 0; i < 5; i++)
        cout << c_out[i] << " ";
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << c_in[i] << " ";

    return 0;
}