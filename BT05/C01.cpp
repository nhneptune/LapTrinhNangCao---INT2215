#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    srand(time(NULL));
    bool mine[m][n];
    int tmp = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mine[i][j] = rand() % 2;
            if (mine[i][j] == 1) tmp++;
            if (tmp > k) mine[i][j] == 0;                    
        }
    }
    char map[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = '*';
        }
    }
    bool lose = false;
    int choose = 0;
    while (!lose && choose != (m * n - k)){
        int x, y;
        cin >> x >> y;
        choose++;
        if (mine[x][y] == true) {
            lose = true;
            break;
        }
        else {
            int count = 0;
            for (int i = x - 1; i <= x + 1; i++) {
                for (int j = y - 1; j <= y + 1; j++) {
                    if (i == x && j == y) continue;
                    if (mine[i][j] == true) count++;
                }
            }
            map[x][y] = count + '0';
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << map[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    if (lose == true){
        cout << "YOU'RE DEAD" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mine[i][j] == true) cout << "X ";
                else cout << map[i][j] << " ";
            }
            cout << endl;
        }
    }
    else cout << "YOU WIN" << endl;

    return 0;
}