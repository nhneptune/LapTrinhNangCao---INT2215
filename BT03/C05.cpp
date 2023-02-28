#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cin >> m;
    cin >> n;
    int bangXoanOc[m][n];
    int giaTri = 1; 
    int vongLap = 1;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            bangXoanOc[i][j] = 0;
        }
    }

    int hang = 0, cot = 0;

    while (giaTri <= m * n){
        if (vongLap % 4 == 1){
            while (cot < n && bangXoanOc[hang][cot] == 0){
                bangXoanOc[hang][cot] = giaTri;
                giaTri++;
                cot++;
            }
            vongLap++;           
            cot--;
            hang++;
            continue;
            
        }
                
        if (vongLap % 4 == 2){
            while (hang < m && bangXoanOc[hang][cot] == 0){
                bangXoanOc[hang][cot] = giaTri;
                giaTri++;
                hang++;
            }
            vongLap++;            
            hang--;
            cot--;
            continue;
            
        }
        
        if (vongLap % 4 == 3){
            while (cot >= 0 && bangXoanOc[hang][cot] == 0){
                bangXoanOc[hang][cot] = giaTri;
                giaTri++;
                cot--;
            }
            vongLap++;       
            cot++;
            hang--;
            continue;           
        }
        
        if (vongLap % 4 == 0){
            while (hang >= 0 && bangXoanOc[hang][cot] == 0){
                bangXoanOc[hang][cot] = giaTri;
                giaTri++;
                hang--;
            }
            vongLap++;
            hang++;
            cot++;
            continue;         
        }        
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << bangXoanOc[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}