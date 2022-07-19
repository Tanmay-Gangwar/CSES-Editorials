#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;
 
ll mod = 1e9 + 7;
 
ll sqrt(ll x){
    if (x == 0 || x == 1) return x;
    ll y = sqrt(x / 4);
    y *= 2;
    if ((y + 1) * (y + 1) <= x) return y + 1;
    return y;
}
 
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
    ll r = sqrt(n);
    ll ans = 0;
    ll inv = inverse(2ll);
    ll l = n;
    for (ll i = 1; i <= r; i++){
        ll u = (n / i - n / (i + 1) + mod) % mod;
        ll v = (n / i + n / (i + 1) + 1) % mod;
        l = min(l, n / (i + 1));
        ll w = (u * v) % mod;
        w = (w * i) % mod;
        w = (w * inv) % mod;
        ans = (ans + w) % mod;
    }
    for (ll i = 1; i <= l; i++){
        ll x = (i * (n / i)) % mod;
        ans = (ans + x) % mod;
    }
    cout << ans << "\n";
 
    return 0;
}
