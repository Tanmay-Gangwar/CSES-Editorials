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

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1), prefix(n + 1);
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    while (q--){
        ll l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << "\n";
    }

    return 0;
}