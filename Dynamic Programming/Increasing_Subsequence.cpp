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
    vector<ll> dp(n + 2, 1e18);
    dp[0] = 0;
    for (ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        ll j = it - dp.begin();
        dp[j] = min(x, dp[j]);
    }
    for (ll i = 1; i <= n + 1; i++){
        // cerr << dp[i] << "\n";
        if (dp[i] == ll(1e18)){
            cout << i - 1 << "\n";
            break;
        }
    }

    return 0;
}