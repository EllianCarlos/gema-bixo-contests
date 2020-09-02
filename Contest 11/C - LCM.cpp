#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 100000007

bool finded[N];

ll gcd(int a, int b) {
    if (a == 0) return b;  
    else return gcd(b % a, a); 
}

ll lcm(int a, int b) {
    return (a /gcd(a, b)) * b;
}

int main() {
    ll b; cin >> b;
    
    ll ans = 0;
    
    for(int a = 1; a <= sqrt(b); a++) {
        if(b % a == 0) {
            ans++;
            if(a != b/a) {
                ans++;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
