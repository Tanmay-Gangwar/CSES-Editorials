#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, mod = 1e9 + 7;
    cin >> n;
    vector<string> a(n);
    for (string &x: a) cin >> x;
    vector<vector<ll>> dp(n, vector<ll>(n));
    dp[0][0] = a[0][0] == '.';
    for (ll i = 1; i < n; i++){
        dp[i][0] = a[i][0] == '.' ? dp[i - 1][0]: 0;
        dp[0][i] = a[0][i] == '.' ? dp[0][i - 1]: 0;
    }
    for (ll i = 1; i < n; i++){
        for (ll j = 1; j < n; j++){
            dp[i][j] = a[i][j] == '.' ? (dp[i - 1][j] + dp[i][j - 1]) % mod: 0;
        }
    }
    cout << dp[n - 1][n - 1] << "\n";

    return 0;
}