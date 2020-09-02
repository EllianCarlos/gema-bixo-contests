#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n; cin >> n;
    map<string, int> quemVotou;
    map<string, int> votos {
        {"quarta", 0},
        {"sexta", 0}
    };
    
    for(int i = 0; i < n; i++) {
        string votou, voto; cin >> votou; cin >> voto;
        if(quemVotou.find(votou) == quemVotou.end()) {
            quemVotou.insert(pair<string, bool>(votou, true));
            auto it = votos.find(voto);
            votos[voto] = (it->second) + 1;
        }
    }
    
    if( (votos.find("quarta")->second) < (votos.find("sexta")->second) ) {
        cout << "sexta" << endl;    
    } else if((votos.find("quarta")->second) > (votos.find("sexta")->second)) {
        cout << "quarta" << endl;
    } else {
        cout << "empate" << endl;
    }
}
