#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mset(a,b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]:" << x << endl
using ll = long long;
using pii = pair<int, int>;

int bitwiseDaMaiorPot(unsigned int n) 
{ 
    return ~(~n & -1) | ; 
} 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    
    cout << n << '\t' << bitwiseDaMaiorPot(n) << endl;
    std::bitset<64> x(n);
    std::cout << "n\t" << x << '\n';
    std::bitset<64> h(~n);
    std::cout << "~n\t" << h << '\n';
    std::bitset<64> k(bitwiseDaMaiorPot(n));
    std::cout << "f(n)\t" << k << '\n';
    std::bitset<64> j(n*-1);
    std::cout << "n*-1\t" << j << '\n';
    std::bitset<64> i(-1);
    std::cout << "-1\t" << i << '\n';
}