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

    ll n, x;
    cin >> n >> x;
    vector<ll> h(n), s(n);
    for (ll &x: h) cin >> x;
    for (ll &x: s) cin >> x;
    vector<ll> dp(x + 1), temp(x + 1);
    for (ll i = h[0]; i <= x; i++) dp[i] = s[0];
    for (ll i = 1; i < n; i++){
        for (ll j = 0; j <= x; j++) {
            if (j >= h[i]) temp[j] = max(dp[j], s[i] + dp[j - h[i]]);
            else temp[j] = dp[j];
        }
        for (ll j = 0; j <= x; j++){
            dp[j] = temp[j];
            temp[j] = 0;
            // cerr << dp[j] << " ";
        }
        // cerr << "\n";
    }
    cout << dp[x] << "\n";

    return 0;
}