#include <bits/stdc++.h>
 
using namespace std;
 
int memo[1000][1000];
 
int solve(string a, string b, int n, int m) {
    if(n >= 1000 || m >= 1000)
        return 0;
        
    if(n >= a.size() || m >= b.size() ) {
        return  memo[n][m] = 0;
    }
    
    if(memo[n][m] != -1) {
        return memo[n][m];
    }
    
    if(a[n] == b[m]) {
        return  memo[n][m] = 1 + solve(a, b, n+1, m+1);
    }
    
    return memo[n][m] = max(solve(a, b, n, m+1), solve(a, b, n+1, m));
}
 
int main() {
    string str1, str2; cin >> str1 >> str2;
    memset(memo, -1, sizeof(memo));
    cout << solve(str1, str2, 0, 0) << endl;
}
