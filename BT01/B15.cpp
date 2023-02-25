#include <iostream>

using namespace std;

int main()
{
    string f0 = "a", f1 = "b";
    cout << f0 << f1;
    for (int i = 2; i <= 10; i++){
        string f2 = f1 + f0;
        cout << f2;
        f0 = f1;
        f1 = f2;
    }
    return 0;
}
