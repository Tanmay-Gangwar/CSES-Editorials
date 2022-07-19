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

    ll a, b;
    cin >> a >> b;
    vector<vector<ll>> dp(a + 1, vector<ll>(b + 1, 1e18));
    for (ll i = 1; i <= a; i++){
        for (ll j = 1; j <= b; j++){
            if (i == j) dp[i][j] = 0;
            else{
                for (ll k = 1; k < j; k++) dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
                for (ll k = 1; k < i; k++) dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
            }
        }
    }
    cout << dp[a][b] << "\n";

    return 0;
}