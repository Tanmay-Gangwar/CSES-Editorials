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

    ll n, k, mod = 1e9 + 7;
    cin >> n >> k;
    vector<ll> a(n), dp(k + 1), temp(k + 1);
    for (ll &x: a) cin >> x;
    dp[0] = 1;
    for (ll x: a){
        for (ll i = 0; i <= k; i++) dp[i] = (dp[i] + (i >= x ? dp[i - x]: 0ll)) % mod;
    }
    cout << dp[k] << "\n";

    return 0;
}