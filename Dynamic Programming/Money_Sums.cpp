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
    ll MX = 1e6;
    vector<bool> dp(MX + 1);
    dp[0] = true;
    for (ll x: a){
        for (ll i = MX; i >= 0; i--){
            if (dp[i] && i + x <= MX) dp[i + x] = true;
        }
    }
    ll cnt = 0;
    for (ll i = 1; i <= MX; i++){
        if (dp[i]) cnt++;
    }
    cout << cnt << "\n";
    for (ll i = 1; i <= MX; i++){
        if (dp[i]) cout << i << " ";
    }

    return 0;
}