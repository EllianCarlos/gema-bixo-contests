#include <bits/stdc++.h>
// #include <algorithm.h>
 
using namespace std;
 
int main() {
   int n, m, k;
   cin >> n >> m >> k;
   queue<int> a;
   // vector<int> a_map;
   for(int i = 0; i < n; i++){
      int n;
      cin >> n; a.push(n); //a_map.push_back(n);
   }
  
   for(int p = 0; p < m; p++) {
       k = min(k, n);
       int rmax = 0;
       vector<int> r(k, 0);
      
       for(int q = 0; q < k; q++) {
           rmax = max(a.front(), rmax);
           r[q] = a.front();
           a.pop();
       }
      
       bool trava = true;
      
       for(int s = 0; s < r.size(); s++) {
           if(r[s] != rmax) {
               a.push(r[s]);
           }
           if(trava && r[s] == rmax) {
               trava = false;
           } else if(!trava && r[s] == rmax) {
               a.push(r[s]);
           }
       }
       n--;
      
       cout << rmax << " ";
   }
 
}

