#include <bits/stdc++.h>

#define pb push_back
#define MAX 1000010
#define INF 1000000000
#define DBG(x) cout <<"[" << #x << "]:" << x << endl;
#define fi first
#define se second
#define mk make_pair
using namespace std;

int n, m, ex = -1;
vector<int> edges[MAX];

void dfs(int v, int *visited) {
    if(v == ex) {
        return;
    }
    visited[v] = 1;
    
    for (auto i = edges[v].begin(); i != edges[v].end(); i++) 
        if (visited[*i] == -1 && *i != ex) 
            dfs(*i, visited);
} 


int countComponents(int *visited) {
    int count = 0;
    
    for (int v = 1; v <= n; v++) {
        if (visited[v] == -1 && v != ex) { 
            dfs(v, visited); 
            count += 1; 
        } 
    }
    
    return count;
}


int main()
{   
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
       int a, b; cin >> a >> b;
       edges[a].pb(b);
       edges[b].pb(a);
    }
    
    int visited[n+1];
    
    memset(visited, -1, sizeof(visited));
    int maxCount = countComponents(visited);
    
    for(int i = 1; i <= n; i++) {
        memset(visited, -1, sizeof(visited));
        ex = i;
        maxCount = max(maxCount, countComponents(visited));    
    }
    
    cout << maxCount << endl;
        
    return 0;
}
