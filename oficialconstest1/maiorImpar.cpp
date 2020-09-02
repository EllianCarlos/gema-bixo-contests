#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

long long esteOuContraparte(long long a, long long b) {
    if(a % 2 and (a > b or (b%2 == 0))) {
        return a;
    } else if(b % 2 and (b > a)) {
        return b;
    }
}

long long acheMaior(long long n) {
    long long maximoD = 1;
    for(long long int k = 1; k < sqrt(n); k++) {
        if( (n % k == 0) ) {
            maximoD = max(maximoD, esteOuContraparte(k, n/k));
        }
        
    }
    return maximoD;
}

int main() {
    long long n; cin >> n;
    int maximo = 1;
    
    if(n % 2) {
        cout << n << endl;
        return 0;
    }
    
    if(n == 1) {
        cout << n << endl;
        return 0;
    }
    
    cout << acheMaior(n) << endl;
    
}