#include <bits/stdc++.h>

using namespace std;

bool compare(pair<long long, long long> a, pair<long long, long long> b) {
   return (a.first - a.second) > (b.first - b.second);
}


int main() {
	long long n; long long sum = 0;
	cin >> n;
	
	pair<long long, long long> a[n];
	
	for (int i = 0; i < n; ++i) {
	    cin >> a[i].first >> a[i].second;
	    sum +=  (n*a[i].second-a[i].first);
    }
	
	sort(a, a+n, compare); // mano como foi dificil fazer essa linha
	
	for(int i = 1; i <= n; i++) {
	    sum += i * (a[i-1].first - a[i-1].second);
	}
	
	cout << sum;
	
	return 0;
}
