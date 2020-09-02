#include <bits/stdc++.h>
 
#define MAXN 1e5
 
using namespace std;


vector<int> edges[(int)MAXN];
int visited[(int)MAXN];
int n, m;

void dfs(int currNode) {
	if (visited[currNode]) return;

	visited[currNode] = 1;

	for (int i = 0; i < edges[currNode].size(); i++) {
		dfs(edges[currNode][i]);
	}
}

int componentesConexos() {
    int count = 0; 
    
    int s = 0;
    for (int v = 1; v <= n; v++) { 
        if (visited[v] == false) { 
            dfs(v); 
            s += 1; 
        } 
    } 
  
    return s; 
}

int main() {
    
    cin >> n >> m;

    for(int i = 1; i <=  m; i++) {
        int node1, node2; cin >> node1 >> node2;
        
        edges[node1].push_back(node2);
        edges[node2].push_back(node1);
    }
    
    for (int v = 0; v < MAXN; v++) 
        visited[v] = 0;
    
    cout << componentesConexos() << endl;
}
