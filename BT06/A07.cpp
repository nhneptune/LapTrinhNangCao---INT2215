#include <iostream>

using namespace std;

void permutation(string s, int low, int high){
    if (low == high) {
        cout << s << endl;
    }
    else {
        for (int i = low; i <= high; i++){
            swap(s[low], s[i]);
            permutation(s, low + 1, high);
            swap(s[low], s[i]);
        }
    }
}

int main()
{
    string s;
    cin >> s;
    permutation(s, 0, s.length() - 1);
    return 0;
}