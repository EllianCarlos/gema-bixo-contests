#include <bits/stdc++.h>

using namespace std;

#define inf (int)1e9
#define N  1000007

typedef long long int ll;

int n, q[N], m;
ll cost;
set<int> edges[N];


int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> q[i];
    }
    
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[b].insert(c);
    }
    
    ll ans=0;
    
    int m = 0;
    
    for(int i=1;i<=n;i++)
    {
        if(edges[i].size())
        {
            auto itr=edges[i].begin();
            ans+=(ll)(*itr);
        }

        else
            m++;
    }

    if(m==1)
        cout << (ans);
    else
        cout << (-1);
    
    return 0;
}
