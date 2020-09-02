#include <bits/stdc++.h>

using namespace std;


int main() {
    string word, newWord = "";
    bool lastCharWasVogal = false;
    cin >> word;
    
    for(int i = 0; i < word.size(); i++){
        if ( (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') && lastCharWasVogal){
            
        }
        else if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
        {
            
            newWord += word[i];
            lastCharWasVogal = true;
        } else {
            newWord += word[i];
            lastCharWasVogal = false;
        }
    }
    
    cout << newWord << endl;
}
