#include <bits/stdc++.h>

using namespace std;

#define inf (int)1e9
#define N (int)1e5 + 7

int d[N];
//int pai[N];
vector< pair<int, int> > edges[N];

int dijikstra(int n, int a, int b){
    for(int i = 1; i <= n; i++) {
        d[i] = inf;
    }
    d[a] = 0;
    
    //pai[a] = -1;
        
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >  pq;
    
    pq.push(make_pair(0,a));
    
    while(pq.size()) {
        int u = pq.top().second;
        int x = pq.top().first;
        pq.pop();
        
        
        if(x > d[u]) continue;
        
        for(int i = 0; i < edges[u].size(); i++){
            int v, w;
            w = edges[u][i].second;
            v = edges[u][i].first;
            
            if( (d[u] + w) < d[v]){
                d[v] = d[u] + w;
                pq.emplace(d[v], v);
            }
        }
    }
    
    if(d[b] < inf) 
        return d[b];
    else
        return -1;
}

int main() {
    int m, n, a; 
    cin >> n >> m >> a;
    
    d[a] = 0;
    
    for(int i = 0; i < m; i++){
        int w, u, v; cin >> v >> u >> w;
        
        edges[u].emplace_back(v, w);
        edges[v].emplace_back(u, w);
    }
    
    dijikstra(n, a, n);
    
    for(int i = 1; i <= n; i++) {
        if(d[i] < inf)
            cout << d[i] << endl;
        else
            cout << -1 << endl;
    }
    
	return 0;
}
