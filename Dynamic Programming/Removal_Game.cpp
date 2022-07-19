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

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x: a) cin >> x;
    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n));
    for (ll x: a) cin >> x;
    for (ll len = 1; len <= n; len++){
        for (ll i = 0; i + len - 1 < n; i++){
            ll j = i + len - 1;
            if (len == 1) dp[i][j] = {a[i], 0ll};
            else {
                ll x = a[i] + dp[i + 1][j].second;
                ll y = a[j] + dp[i][j - 1].second;
                if (x > y) dp[i][j] = {x, dp[i + 1][j].first};
                else dp[i][j] = {y, dp[i][j - 1].first};
            }
            // cerr << i << " " << j << " " << dp[i][j].first << " " << dp[i][j].second << "\n";
        }
    }
    cout << dp[0][n - 1].first << "\n";

    return 0;
}