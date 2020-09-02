#include<bits/stdc++.h>
#include<string.h>
#include <stdlib.h>
 
#define MAX (int)1e3
 
using namespace std;
 
vector<int> a;
int N, X;
int achados = 0;
int escolhidos[MAX];

int solve(int i) {
    if(i == N) {
        int sum = 0;
        for(int j = 0; j < N; j++) {
            sum += escolhidos[j]*a[j];
        }
        
        if(sum == X) {
            achados++;
        }
        return 0;
    }
    
    escolhidos[i] = 1;
    solve(i+1);
    
    escolhidos[i] = 0;
    solve(i+1);
}
 
int main() {
    cin >> N >> X;
    for(int n = 0; n < N; n++) {
        int s;
        cin >> s;
        a.push_back(s);
    }
    
    solve(0);
    
    cout << achados; 
}
