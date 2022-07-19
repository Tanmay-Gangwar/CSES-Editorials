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

    string a, b;
    cin >> a >> b;
    a = "#" + a;
    b = "#" + b;
    ll n = a.length();
    ll m = b.length();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for (ll i = 1; i <= n; i++) dp[i][0] = i;
    for (ll j = 1; j <= m; j++) dp[0][j] = j;
    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= m; j++){
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(1 + dp[i - 1][j - 1], min(1 + dp[i - 1][j], 1 + dp[i][j - 1]));
        }
    }
    cout << dp[n][m] << "\n";

    return 0;
}