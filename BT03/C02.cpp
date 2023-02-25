#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int i = 0, j = s.length() - 1;
    while(i != j){
        if(s[i] != s[j]){
            cout << "No";
            return 0;
        }
        i++;
        j--;
    }
    cout << "Yes";
    return 0;
}