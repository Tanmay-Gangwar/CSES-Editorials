#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;

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

void Solve(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll p = power(b, c, mod - 1);
    cout << power(a, p, mod) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        // cout << "Case #" << i << ": ";
        // cerr << "Case #" << i << ": \n";
        Solve();
    }

    return 0;
}