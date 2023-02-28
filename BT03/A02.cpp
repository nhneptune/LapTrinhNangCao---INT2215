#include <iostream>

using namespace std;

int main()
{
    // Phần a
    string s1;
    
    for (int i = 0; i < s1.length(); i++)
        cout << s1[i];
    cout << endl;
    cout << s1 << endl;

    // Phần b
    string s2 = "namdeptraivodichvutru";

    for (int i = 0; i < s2.length(); i++)
        cout << s2[i];
    cout << endl;
    cout << s2 << endl;

    return 0;
}