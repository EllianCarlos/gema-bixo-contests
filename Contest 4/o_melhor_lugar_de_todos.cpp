#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int N, k; cin >> N;
    
    for(int i =0; i < ((N/2) + 2*(N%2 != 0)) ; i++ ) {
        cin >> k;
    }
    
    cout << k;
}


