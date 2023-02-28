#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    char input[m][n];

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> input[i][j];
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(input[i][j] == '.'){
                int count = 0;
                if(input[i][j+1] == '*'){
                    count++;
                }
                if(input[i][j-1] == '*'){
                    count++;
                }
                if(input[i+1][j] == '*'){
                    count++;
                }
                if (input[i-1][j] == '*'){
                    count++;
                }
                if (input[i+1][j+1] == '*'){
                    count++;
                }
                if (input[i+1][j-1] == '*'){
                    count++;
                }
                if (input[i-1][j+1] == '*'){
                    count++;
                }
                if (input[i-1][j-1] == '*'){
                    count++;
                }
                input[i][j] = char('0' + count);
            }
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << input[i][j];
        }
        cout << endl;
    }

    return 0;
}