#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int value;
    int size;
    ifstream file("inputA02.txt");
    if (file.is_open()){
        file >> value;
        file >> size;
        while (!file.eof()){
            int *arr = new int[size];
            for (int i = 0; i < size; i++){
                file >> arr[i];
            }
            for (int i = 0; i < size; i++){
                if (arr[i] == value){
                    cout << i;
                    return 0;
                }
            }
        }        
    }
    else {
        cout << "File not found";
    }
    return 0;
}