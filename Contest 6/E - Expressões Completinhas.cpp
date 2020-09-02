#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  string str;
  int n;
  stack<int> a;
  a.push(0);
  bool s = false;
  cin >> n >> str;
 
  for(int i = 0; i < n; i++) {
      if(str[i] == '(') {
          a.push(1);
      }
      if(str[i] == '{') {
          a.push(2);
      }
      if(str[i] == '[') {
          a.push(3);
      }
      if(str[i] == ')' && a.top() == 1) {
          a.pop();
      } else if (str[i] == ')' && a.top() != 1){
          s = true;
          break;
      }
      if(str[i] == '}' && a.top() == 2) {
          a.pop();
      } else if (str[i] == '}' && a.top() != 2){
          s = true;
          break;
      }
      if(str[i] == ']' && a.top() == 3) {
          a.pop();
      } else if (str[i] == ']' && a.top() != 3){
          s = true;
          break;
      }
     
  }
 
  if(s == false && a.size() == 1) {
      cout << "COMPLETINHA";
  } else {
      cout << "DEU RUIM";
  }
}

