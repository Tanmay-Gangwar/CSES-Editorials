#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

ll solve(ll n, ll k){
    if (n == 1) return 1;
    if (2 * k <= n) return 2 * k;
    ll x = solve((n + 1) / 2, k - n / 2);
    if (n & 1) return (x == 1 ? n: 2 * x - 3);
    return 2 * x - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll q;
    cin >> q;
    while (q--){
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }

    return 0;
}