#include<bits/stdc++.h>
#include<string.h>

#define MAX 1e3

using namespace std;

int N, M;
int visited[(int)MAX][(int)MAX];

int walk(int x,  int y, string a[]) {
    if(visited[x][y] == 1) {
        cout << "EOQ";
        return 0;
    }
    if(x >= N || x < 0 || y >= M || y < 0 ) {
        cout << "AE MLK";
        
        return 0;
    } else {
        visited[x][y] = 1;
        if(a[x][y] == 'R') {
            walk(x, y+1, a);
        }
        if(a[x][y] == 'L') {
            walk(x, y-1, a);
        }
        if(a[x][y] == 'U') {
            walk(x-1, y, a);
        }
        if(a[x][y] == 'D') {
            walk(x+1, y, a);
        }
    }
}

int main() {
    memset(visited, 0, sizeof(visited));
    cin >> N >> M;
    
    string a[N];
    
    for(int n=0; n< N; n++) {
        cin >> a[n];
    }
    
    int x, y; cin >> x >> y;
    
    walk(x, y, a);
}
