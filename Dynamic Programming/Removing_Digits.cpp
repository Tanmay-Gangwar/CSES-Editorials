#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= 9; i++) dp[i] = 1;
    for (int i = 10; i <= n; i++){
        int temp = i;
        while (temp){
            dp[i] = min(dp[i], 1 + dp[i - temp % 10]);
            temp /= 10;
        }
    }
    cout << dp[n] << "\n";
 
    return 0;
}