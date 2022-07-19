#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int mod = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<vector<int>> dp(n, vector<int>(m + 2));
    if (a[0]) dp[0][a[0]] = 1;
    else for (int i = 1; i <= m; i++) dp[0][i] = 1;
    for (int i = 1; i < n; i++){
        if (a[i]) dp[i][a[i]] = ((dp[i - 1][a[i] - 1] + dp[i - 1][a[i]]) % mod + dp[i - 1][a[i] + 1]) % mod;
        else for (int j = 1; j <= m; j++)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) ans = (ans + dp[n - 1][j]) % mod;
    cout << ans << "\n";
 
    return 0;
}