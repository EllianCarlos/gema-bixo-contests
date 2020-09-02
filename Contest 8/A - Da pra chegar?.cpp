#include <bits/stdc++.h>
 
#define MAXN 1e5
 
using namespace std;


vector<int> edges[(int)MAXN];
int visited[(int)MAXN];
bool achou = false;

void dfs(int currNode, int nodeToFind) {
	if (visited[currNode] || achou) return;

	visited[currNode] = 1;
	
	if(currNode == nodeToFind) {
	    achou = true;
	    return;
	}

	for (int i = 0; i < edges[currNode].size(); i++) {
		dfs(edges[currNode][i], nodeToFind);
	}
}

int main() {
    
    int n, m, a, b; cin >> n >> m >> a >> b;

    for(int i = 1; i <=  m; i++) {
        int node1, node2; cin >> node1 >> node2;
        
        edges[node1-1].push_back(node2-1);
    }
    
    dfs(a-1, b-1);
    
    if(achou) {
        cout << "SIM";
    } else {
        cout << "NAO";
    }
    
}
