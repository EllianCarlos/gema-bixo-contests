#include <bits/stdc++.h>
#include <math.h>

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


int main() {
    ll a, b;
    
    cin >> a >> b;
    
    cout << lcm(a, (int)pow(10, b)) << endl;
    
    return 0;
}
