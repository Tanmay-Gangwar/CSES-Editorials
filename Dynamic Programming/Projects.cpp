#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;


bool cmp(array<ll, 3> &x, array<ll, 3> &y){
    // if (x[1] == y[1]) return x[2] < y[2];
    return x[1] < y[1];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<array<ll, 3>> a(n + 1);
    vector<ll> dp(n + 1);
    dp[0] = 0;
    for (ll i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    sort(a.begin(), a.end(), cmp);

    set<pair<ll, ll>> st;
    for (ll i = 1; i <= n; i++){
        auto it = st.lower_bound({a[i][0], 0});
        if (it == st.begin()) dp[i] = max(dp[i - 1], a[i][2]);
        else{
            --it;
            dp[i] = max(dp[i - 1], a[i][2] + dp[it->second]);
        }
        st.insert({a[i][1], i});
        // cerr << a[i][0] << " " << a[i][1] << " " << a[i][2] << "\n";
        // cerr << dp[i] << "\n";
    }
    cout << dp[n] << "\n";


    return 0;
}