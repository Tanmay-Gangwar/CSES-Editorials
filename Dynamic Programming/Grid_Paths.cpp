#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, mod = 1e9 + 7;
    cin >> n;
    vector<string> a(n);
    for (string &x: a) cin >> x;
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = a[0][0] == '.';
    for (int i = 1; i < n; i++){
        dp[i][0] = a[i][0] == '.' ? dp[i - 1][0]: 0;
        dp[0][i] = a[0][i] == '.' ? dp[0][i - 1]: 0;
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            dp[i][j] = a[i][j] == '.' ? (dp[i - 1][j] + dp[i][j - 1]) % mod: 0;
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
 
    return 0;
}