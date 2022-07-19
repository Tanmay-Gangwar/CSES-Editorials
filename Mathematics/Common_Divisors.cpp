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
    ll mx = 1e6;
    vector<ll> cnt(mx + 1);
    for (ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        cnt[x]++;
    }
    for (ll i = mx; i > 0; i--){
        ll c = 0;
        for (ll j = i; j <= mx; j += i){
            c += cnt[j];
        }
        if (c > 1){
            cout << i << "\n";
            break;
        }
    }
 
    return 0;
}