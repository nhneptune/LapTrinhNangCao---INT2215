#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n % 100 == 0 && n % 400 == 0){
        cout << "true";
        return 0;
    }
    if (n % 4 == 0){
        cout << "true";
    }
    else {
        cout << "false";
    }
    return 0;
}