#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

ll mod = 1e9 + 7;
ll a[1000001], b[1000001];

void Solve(){
    ll n;
    cin >> n;
    cout << (a[n] + b[n]) % mod << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    a[1] = 1;
    b[1] = 1;
    for (ll i = 2; i <= 1000000; i++){
        a[i] = (4 * a[i - 1] + b[i - 1]) % mod;
        b[i] = (a[i - 1] + 2 * b[i - 1]) % mod;
    }

    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        // cout << "Case #" << i << ": ";
        // cerr << "Case #" << i << ": \n";
        Solve();
    }

    return 0;
}