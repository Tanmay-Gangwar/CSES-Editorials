#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

ll cnt(ll x){
    if (x == 0) return 0;
    string s = to_string(x);
    reverse(s.begin(), s.end());
    ll ans = 0, p = 1, n = s.length();
    for (ll i = 0; i < n; i++){
        if (i + 1 < n && s[i] > s[i + 1]) ans += max(s[i] - '1', 1) * p;
        else ans += max(s[i] - '0', 1) * p;
        p *= 9;
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    ll a, b;
    cin >> a >> b;
    cout << cnt(b + 1) - cnt(a) << "\n";

    return 0;
}