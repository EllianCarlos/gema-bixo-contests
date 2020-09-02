#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int N, M; cin >> N >> M;
    int matrix[N][M];
    int cols[M];
    
    memset(cols, -1, sizeof(cols));
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            cin >> matrix[i][j];
            if(cols[j] != 1 && matrix[i][j] == 0) {
                cols[j] = 1;
            }
        }
    
    for(int j = 0; j < M; j++) {
        if(cols[j] != 1) {
            cout << 'N';
            return 0;
        }
    }
    
    cout << 'S';
    return 0;
}

