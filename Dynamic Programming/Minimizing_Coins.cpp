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

    ll n, k, inf = 1e18;
    cin >> n >> k;
    vector<ll> a(n), dp(k + 1, inf);
    for (ll &x: a) cin >> x;
    dp[0] = 0;
    for (ll i = 1; i <= k; i++){
        for (ll x: a){
            if (i >= x) dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }
    if (dp[k] == inf) dp[k] = -1;
    cout << dp[k] << "\n";

    return 0;
}