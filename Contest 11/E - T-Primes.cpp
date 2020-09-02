#include <bits/stdc++.h>
#include <math.h>

using namespace std;

typedef long long ll;

#define N 100005

ll modulo(ll base, ll exponent, ll mod) 
{ 
    ll x = 1; 
    ll y = base; 
    while (exponent > 0) 
    { 
        if (exponent % 2 == 1) 
            x = (x * y) % mod; 
  
        y = (y * y) % mod; 
        exponent = exponent / 2; 
    } 
  
    return x % mod; 
} 
  
// To calculate Jacobian symbol of a given number 
int calculateJacobian(long long a, long long n) 
{ 
    if (!a) 
        return 0;// (0/n) = 0 
  
    int ans = 1; 
    if (a < 0) 
    { 
        a = -a; // (a/n) = (-a/n)*(-1/n) 
        if (n % 4 == 3) 
            ans = -ans; // (-1/n) = -1 if n = 3 (mod 4) 
    } 
  
    if (a == 1) 
        return ans;// (1/n) = 1 
  
    while (a) 
    { 
        if (a < 0) 
        { 
            a = -a;// (a/n) = (-a/n)*(-1/n) 
            if (n % 4 == 3) 
                ans = -ans;// (-1/n) = -1 if n = 3 (mod 4) 
        } 
  
        while (a % 2 == 0) 
        { 
            a = a / 2; 
            if (n % 8 == 3 || n % 8 == 5) 
                ans = -ans; 
  
        } 
  
        swap(a, n); 
  
        if (a % 4 == 3 && n % 4 == 3) 
            ans = -ans; 
        a = a % n; 
  
        if (a > n / 2) 
            a = a - n; 
  
    } 
  
    if (n == 1) 
        return ans; 
  
    return 0; 
} 
  
// To perform the Solovay-Strassen Primality Test 
bool solovoyStrassen(long long p, int iterations) 
{ 
    if (p < 2) 
        return false; 
    if (p != 2 && p % 2 == 0) 
        return false; 
  
    for (int i = 0; i < iterations; i++) 
    { 
        // Generate a random number a 
        long long a = rand() % (p - 1) + 1; 
        long long jacobian = (p + calculateJacobian(a, p)) % p; 
        long long mod = modulo(a, (p - 1) / 2, p); 
  
        if (!jacobian || mod != jacobian) 
            return false; 
    } 
    return true; 
} 

int main() {
    ll n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        double sq = sqrt(a);
        
        if(sq - (int)sq == 0.0 ) {
            if(solovoyStrassen(sq, 3)) {
                cout << "YES\n";    
            } else {
                cout << "NO\n";
            }
            
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
