#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.length();
    int l2 = s2.length();
    count = 0;
    for (int i = 0; i < l2; i++){
        if (s1[i] == s2[i]){
            if (strcmp(s1, s2 + i) == 0)
                count++;
        }
    }
    cout << count << endl;
    return 0;
}