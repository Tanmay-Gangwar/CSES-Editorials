#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (char c: s) cnt[c - 'A']++;
    char parity = '#';
 
    for (int i = 0; i < 26; i++){
        if (cnt[i] & 1){
            if (parity != '#'){
                cout << "NO SOLUTION\n";
                return 0;
            }
            parity = 'A' + i;
        }
    }
 
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < cnt[i] / 2; j++){
            cout << (char)('A' + i);
        }
    }
    if (parity != '#') cout << parity;
    for (int i = 25; i >= 0; i--){
        for (int j = 0; j < cnt[i] / 2; j++){
            cout << (char)('A' + i);
        }
    }
 
    return 0;
}