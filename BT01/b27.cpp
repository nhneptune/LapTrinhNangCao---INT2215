#include <iostream>

using namespace std;

int main()
{
    while( 1 != 0){
        int n;
        cin >> n;
        if (n == -1){
            break;
        }
        cout << (n >= 0 && n % 5 == 0 ? n/5 : -1) << endl;
    }
    cout << "Bye" << endl;
    return 0;
}