#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, k, inf = 1e9;
    cin >> n >> k;
    vector<int> a(n), dp(k + 1, inf);
    for (int &x: a) cin >> x;
    dp[0] = 0;
    for (int i = 1; i <= k; i++){
        for (int x: a){
            if (i >= x) dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }
    if (dp[k] == inf) dp[k] = -1;
    cout << dp[k] << "\n";
 
    return 0;
}