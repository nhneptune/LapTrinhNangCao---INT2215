#include <iostream>

using namespace std;

int main()
{
    int x, y;
    int tmp;
    cin >> x;
    cout << x << " ";
    y = x;
    while (x >= 0){
        cin >> tmp;
        x = tmp;
        if (x != y) cout << x << " ";
        y = x;
    }

    return 0;
}
