#include <bits/stdc++.h>

#define pb push_back
#define MAX 1010
#define INF 1000000000
#define DBG(x) cout <<"[" << #x << "]:" << x << endl;

using namespace std;

bool achou;
int n, m, a, b;
vector<int> edges[MAX];
set<pair<int, int>> con;

void bfs(int root, pair<int, int> excludedCon) {
	vector<int>  vis(MAX, 0);
	queue <int> q;
	q.push(root);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		if(u == b) {
		    achou = true;
		    return;
		}

		vis[u] = 1;

		for(int i = 0; i < edges[u].size(); i++){
			int v = edges[u][i];
			
			if( !
			    ((u == excludedCon.first && v == excludedCon.second) 
			    || 
			    (v == excludedCon.first && u == excludedCon.second)) ) {
		         // cout << "u: " << u << " v: " << v << endl;
			    if (!vis[v])
			        q.push(v);   
			}
		}
	}
}

int main()
{   
    cin >> n >> m >> a >> b;
    
    for(int i = 0; i < m; i++) {
        int p, q; cin >> p >> q;
        edges[p].pb(q);
        edges[q].pb(p);
        con.insert(make_pair(p, q));
    }
    
    for(auto it = con.begin(); it != con.end(); it++) {
        
        achou = false;
        bfs(a, *it);
        if(!achou) {
            // cout << "breka" << endl;
            // cout <<  it->first << " " << it->second << endl;
            break;
        }
        
    }
    
    if (achou)
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;
    
    return 0;
}
