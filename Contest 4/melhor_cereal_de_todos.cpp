#include <bits/stdc++.h>

using namespace std;

int sum = 0;

int  loppas(int lastNumber, int n) {
    if(n == 0) {
        sum++;
        return 1;    
    }
    
    for(int i = lastNumber; i <= n; i += lastNumber) {
        loppas(i, n-i);  
    }
}

int main() {
    int n; cin >> n;
    
    loppas(1, n);
    cout << sum;
}
