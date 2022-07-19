#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for (int &x: h) cin >> x;
    for (int &x: s) cin >> x;
    vector<int> dp(x + 1), temp(x + 1);
    for (int i = h[0]; i <= x; i++) dp[i] = s[0];
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= x; j++) {
            if (j >= h[i]) temp[j] = max(dp[j], s[i] + dp[j - h[i]]);
            else temp[j] = dp[j];
        }
        for (int j = 0; j <= x; j++){
            dp[j] = temp[j];
            temp[j] = 0;
        }
    }
    cout << dp[x] << "\n";
 
    return 0;
}