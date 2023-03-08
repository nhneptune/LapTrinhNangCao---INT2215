#include <iostream>

using namespace std;

void combination(string s, int n){
    if(n < 1) cout << s << endl;
    else {
        for (int i = 0; i < s.length(); i++){
            string s1 = s.substr(0, i) + s.substr(i + 1);
            combination(s1, n - 1);
        }
    }
}

int main()
{
    string s;
    cin >> s;
    combination(s, s.length());
    return 0;
}