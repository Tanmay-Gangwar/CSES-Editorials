#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
    int n, k, mod = 1e9 + 7;
    cin >> n >> k;
    vector<int> a(n), dp(k + 1);
    for (int &z: a) cin >> z;
    dp[0] = 1;
    for (int i = 1; i <= k; i++){
        for (int x: a){
            if (i >= x) dp[i] = (dp[i] + dp[i - x]) % mod;
        }
    }
    cout << dp[k] << "\n";
    return 0;
}