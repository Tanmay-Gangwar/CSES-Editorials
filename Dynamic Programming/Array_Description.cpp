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

    ll mod = 1e9 + 7;
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll &x: a) cin >> x;
    vector<vector<ll>> dp(n, vector<ll>(m + 2));
    if (a[0]) dp[0][a[0]] = 1;
    else for (ll i = 1; i <= m; i++) dp[0][i] = 1;
    for (ll i = 1; i < n; i++){
        if (a[i]) dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % mod;
        else for (ll j = 1; j <= m; j++)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
    }
    ll ans = 0;
    for (ll j = 1; j <= m; j++) ans = (ans + dp[n - 1][j]) % mod;
    cout << ans << "\n";

    return 0;
}