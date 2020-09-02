#include<bits/stdc++.h>
#include<string.h>
#include <stdlib.h>2 0.5

 
using namespace std;


int main() {
    int n;
    double p;
    
    cin >> n >> p;
    
    double pp = p*(1-p);
    double prob = p*(1-pow(pp, (n+1)/2))/(1-pp);
    
    // for(int i = 1; i < N; i++){
    //     prob += p*pow(pp, i);
    // }
    
    cout << fixed << setprecision(4) << prob;
	}
