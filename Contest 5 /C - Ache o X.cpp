#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
 
using namespace std;

int N, M;

int searchSmallest(int v[], int x) {
    int inicio = 0, fim = N - 1;
    int n = (inicio + fim)/2, minimo = pow(10, 9), flagMin;
    int lastDiff = 0, diff;
    
    while(inicio <= fim) {
        int diff = abs(v[n]-x);
        if(diff < minimo) {
            flagMin = n;
        }
        minimo = min(minimo, diff);
        if(inicio == fim) {
            if(n > 0)
            if(abs(x-v[n-1]) <= abs(x-v[n])){
                n--;
                flagMin = n;
            }
            if(n < N -1)
            if( abs(x-v[n]) > abs(x-v[n+1])) {
                n++;
                flagMin = n;
                
            }
            break;
        }
        
        
        
        if(x < v[n]) {
            fim = n;
        } else if(x > v[n]) {
            inicio = n + 1;
        } else {
            break;
        }
        n = (inicio + fim)/2;
    }
    cout << v[flagMin] << endl;
}


int main() {

    cin >> N >> M;
    int V[N];
    int x;
    int minimo = pow(10,9);
    
    for(int i = 0; i < N; i++){
        cin >> V[i];
        
    }
    
    for(int j = 0; j < M; j++){
        cin >> x;
        searchSmallest(V, x);
    }
}
