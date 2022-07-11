#include<bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    string s;
    cin >> s;
    int ans = 0;
    string res = "";
    sort(s.begin(), s.end());
    do{
        res += s;
        res += '\n';
        ans++;
    }while (next_permutation(s.begin(), s.end()));
    cout << ans << "\n" << res << "\n";
 
    return 0;
}