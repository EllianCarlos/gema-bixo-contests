#include <bits/stdc++.h>

using namespace std;

#define N  1000007

int n, m, k, x, y, ant_y;
int pai[N], sz[N], num[N];

void init() {
    for(int k = 0; k <= n; k++) {
        pai[k] = k;
        sz[k] = 1;
        num[N] = 1;
    }
}

int find(int x) {
    if(pai[x] == x) return x;
    else return pai[x] = find(pai[x]);
}

void unite(int a, int b) {
    // cout << a << ' ' << b << endl;
    int lider_a = find(a);
    int lider_b = find(b);

    if(sz[lider_a] > sz[lider_b]) swap(lider_b, lider_a);
    
    pai[lider_a] = lider_b;
    // sz[lider_b] += sz[lider_a];
    
}

int main() {
    
    cin >> n >> m;
    
    init();
    
    for(int i = 0; i < m; i++) {
        cin >> k;
        // cout << "linha: " << k << endl;
        
        for(int j = 1; j <= k; j++) {
            cin >> y;
            // cout << "y: " <<  y << " ";
            if(j == 1) {
                ant_y = y;
                continue;
            }
            
            
            unite(ant_y, y);
            ant_y = y;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        num[find(i)]++;
    }
    
    for(int i = 1; i <= n; i++) {
        cout << num[find(i)] << ' ';
    }
    
    cout << endl;
    
}
