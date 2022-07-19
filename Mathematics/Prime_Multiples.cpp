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

    ll n, k;
    cin >> n >> k;
    vector<ll> a(k);
    for (ll &x: a) cin >> x;
    ll ans = 0;
    for (ll i = 1; i < (1ll << k); i++){
        ll cnt = 0;
        ll p = 1;
        bool valid = true;
        for (ll bit = 0; bit < k; bit++){
            if (i >> bit & 1){
                if (a[bit] <= n / p) {
                    p *= a[bit];
                    cnt++;
                }
                else{
                    valid = false;
                    break;
                }
            }
        }
        if (valid){
            if (cnt % 2 == 0) p *= -1;
            ans += n / p;
        }
    }
    cout << ans << "\n";

    return 0;
}