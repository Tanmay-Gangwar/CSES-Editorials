#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

ll mod = 1e9 + 7;

template<class __num>
__num power(__num a, __num n, __num mod){
    __num ans = 1;
    while (n){
        if (n & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}

ll inverse(ll x){
    return power(x, mod - 2, mod);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    ll s = n * (n + 1) / 2;
    if (s & 1){
        cout << "0\n";
        return 0;
    }
    vector<ll> dp(s + 1);
    dp[0] = 1;
    for (ll i = 1; i <= n; i++){
        for (ll j = s; j >= 0; j--){
            dp[j + i] = (dp[j + i] + dp[j]) % mod;
        }
    }
    cout << (dp[s / 2] * inverse(2)) % mod;

    return 0;
}