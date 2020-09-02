
#include <bits/stdc++.h>

using namespace std;

int main() {
   string str;
   stack<int> a;
   bool s = false;
   cin >> str;
   
   for(int i = 0; i < str.size(); i++) {
       if(str[i] == '(') {
           a.push(1);
       }
       if(str[i] == ')' && a.size() == 0) {
           s = true;
           break;
       }
       if(str[i] == ')' && a.size() > 0) {
           a.pop();
       }
   }
   
   if(s == false && a.size() == 0) {
       cout << "YES";
   } else {
       cout << "NO";
   }
}
