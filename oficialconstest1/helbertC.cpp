#include<bits/stdc++.h>

using namespace std;

int realizar_jogada(int n1, int n2, int n3);

int main(){
    int N1, N2, N3;
    cin >> N1 >> N2 >> N3;
    cout << realizar_jogada(N1, N2, N3) << endl;

    return 0;
}

int realizar_jogada(int n1, int n2, int n3){
    if(!n1 || !n2 || !n3)
        return 1;
    int cont = 0;
    if(n1 <= n2)
        cont += realizar_jogada(n1, n2-n1, n3);
    if(n1 <= n3)
        cont += realizar_jogada(n1, n2, n3-n1);
    if(n2 <= n1)
        cont += realizar_jogada(n1-n2, n2, n3);
    if(n2 <= n3)
        cont += realizar_jogada(n1, n2, n3-n2);
    if(n3 <= n1)
        cont += realizar_jogada(n1-n3, n2, n3);
    if(n3 <= n2)
        cont += realizar_jogada(n1, n2-n3, n3);
    return cont;

}