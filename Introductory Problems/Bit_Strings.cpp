#include<bits/stdc++.h>
using namespace std; 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, mod = 1e9 + 7;
    cin >> n;
    int ans = 1, a = 2;
    while (n){
        if (n & 1) ans = ((long long)a * ans) % mod;
        a = ((long long)a * a) % mod;
        n >>= 1;
    }
    cout << ans << "\n";
 
 
    return 0;
}