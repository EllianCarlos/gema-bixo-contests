#include <bits/stdc++.h>

#define pb push_back
#define MAX 1000010
#define INF 1000000000
#define DBG(x) cout <<"[" << #x << "]:" << x << endl;
#define fi first
#define se second
#define mk make_pair
using namespace std;

int n, m;
int deg[MAX];
vector<int> edges[MAX];
vector<int> comp;

void dfs(int v, int *visited) {
	visited[v] = true;
	comp.pb(v);
	
	for (auto to : edges[v])
		if (visited[to] == -1)
			dfs(to, visited);
}


int main()
{   
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        edges[a].pb(b);
        edges[b].pb(a);
        ++deg[a];
        ++deg[b];
    }
    
    int visited[n+1];
    
    memset(visited, -1, sizeof(visited));
        
    int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (visited[i] == -1) {
			comp.clear();
			dfs(i, visited);
			bool ok = true;
			for (auto v : comp) ok &= deg[v] == 2;
			if (ok) ++ans;
		}
	}
	
	printf("%d\n", ans);
    
    return 0;
}
