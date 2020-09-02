#include <bits/stdc++.h>
 
#define MAXN 1e5
#define INF 1e8
 
using namespace std;
int m, n, a, b;
vector<int> edges[(int)MAXN+1];
vector<int> dist;

int bfs(int a, int b) {
    
    queue<int> q;
    int visited[n+1];
    int anterior[n+1];
    
    
    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
        dist.push_back(-1);
        anterior[i] = -1;
    }
    
    visited[a] = 1;
    dist[a] = 0;
    q.push(a);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int i = 0; i < edges[u].size(); i++) {
            if(!visited[edges[u][i]]) {
                
                visited[edges[u][i]] = 1;
                dist[edges[u][i]] = dist[u] + 1;
                anterior[edges[u][i]] = u;
                q.push(edges[u][i]);
                
                if(edges[u][i] == b){
                    return dist[edges[u][i]];
                }
            }
        }
    }
    
    return -1;
}

int main() {
    cin >> n >> m >> a >> b;

    for(int i = 1; i <= m; i++) {
        int n1, n2; cin >> n1 >> n2;
        edges[n1].push_back(n2);
        edges[n2].push_back(n1);
    }
    if(a == b) {
        cout << 0 << endl;    
    }else if(edges[a].size() < 1 || edges[b].size() < 1) {
        cout << -1 << endl;
    } else {
        cout << bfs(a, b) << endl;
    }
 }
