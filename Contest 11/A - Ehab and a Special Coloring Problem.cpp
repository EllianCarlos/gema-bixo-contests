#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 100005

ll gcd(int a, int b) {
    if (a == 0) return b;  
    else return gcd(b % a, a); 
}
 
ll lcm(int a, int b) {
    return (a /gcd(a, b)) * b;
}

int ans[N];

int main() {
    ll a;
    int c = 0;
    
    cin >> a;
    memset(ans, 0, sizeof(ans));
    for(int i = 2; i <= a; i++) {
        if(!ans[i]) {
            ans[i]=++c;
			for (int j=i;j<=a;j+=i)
			    ans[j]=ans[i];
        }
        cout << ans[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}
