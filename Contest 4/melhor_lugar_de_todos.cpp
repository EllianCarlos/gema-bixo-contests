#include <bits/stdc++.h>
#include <stdio.h> 
#include <cmath> 
using namespace std;
 
int main() {
    int minDistance = 0, minPosition = 0, n, number; cin >> n;
    int numbers[n];
    for(int i=0; i < n; i++  ) {
        scanf("%u ", &number);
        numbers[i] = number;
        if( n%2 == 0 && i == floor(n/2)-1) {
            minPosition = number;
        }
        if(n%2 != 0 && i == ((int)floor(n/2))) {
            minPosition = number;
        }
    }

    cout << minPosition;
    return 0;
}
    
