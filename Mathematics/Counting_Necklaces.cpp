#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
ll power(ll a, ll n){
    ll ans = 1;
    while (n){
        if (n & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}

ll inverse(ll a){
    return power(a, mod - 2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for (ll i = 0; i < n; i++){
        ans = (ans + power(m, __gcd(i, n))) % mod;
    }
    ans = (ans * inverse(n)) % mod;
    cout << ans << "\n";

    return 0;
}