#include <bits/stdc++.h>

using namespace std;

#define inf (int)1e9
#define N  1000007
#define alphabet 256 

typedef long long int ll;

string a, b;
int n, m = 0;
int pai[alphabet];
vector<char> v; 

void init() {
    for(int i=0;i<26;i++) 
	    pai[i]=i;
}

int find(int k){
	return pai[k]==k ? k : pai[k] = find(pai[k]);
}

void unite(int p, int q) {
    m++;
    int lider_p = find(p);
    int lider_q = find(q);

    pai[lider_p] = lider_q;
}
 
int main(){
	int n;
	
	cin >> n >> a >> b;
	
	init();
	
	for(int i=0;i<n;i++) {
		if( find(a[i]-'a') != find(b[i]-'a') ) {
			unite(a[i]-'a', b[i]-'a');
			
			v.push_back(a[i]),v.push_back(b[i]);
		}
	}
	
	cout << m << endl;
	
	for(int i=0;i<v.size();i+=2)
		cout<< v[i] <<" "<< v[i+1] << '\n';
}
