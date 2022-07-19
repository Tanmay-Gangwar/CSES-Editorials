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

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll &x: a) cin >> x;
    vector<pair<ll, ll>> dp(1 << n, {n + 1, m + 1});
    dp[0] = {0, m + 1};
    for (ll i = 1; i < (1 << n); i++){
        for (ll bit = 0; bit < n; bit++){
            if ((i >> bit) & 1){
                pair<ll, ll> temp = dp[(1 << bit) ^ i];
                if (temp.second + a[bit] <= m) temp.second += a[bit];
                else temp.first++, temp.second = a[bit];
                dp[i] = min(dp[i], temp);
            }
        }
    }
    cout << dp[(1 << n) - 1].first << "\n";

    return 0;
}