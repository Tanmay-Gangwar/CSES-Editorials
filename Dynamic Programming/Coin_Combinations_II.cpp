#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, k, mod = 1e9 + 7;
    cin >> n >> k;
    vector<int> a(n), dp(k + 1), temp(k + 1);
    for (int &x: a) cin >> x;
    dp[0] = 1;
    for (int x: a){
        for (int i = 0; i <= k; i++) dp[i] = (dp[i] + (i >= x ? dp[i - x]: 0)) % mod;
    }
    cout << dp[k] << "\n";
 
    return 0;
}