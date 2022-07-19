#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

void Solve(){
    ll n;
    cin >> n;
    // vector<ll> a(n);
    // for (ll &x: a) cin >> x;
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1)));
    for (ll i = 0; i <= n; i++){
        for (ll j = 0; j <= n; j++){
            for (ll k = 0; k <= n; k++){
                for (ll l = 0; l < i; l++){
                    if (!dp[l][j][k]){
                        dp[i][j][k] = true;
                        break;
                    }
                }
                for (ll l = 0; l < j; l++){
                    if (!dp[i][l][k]){
                        dp[i][j][k] = true;
                        break;
                    }
                }
                for (ll l = 0; l < k; l++){
                    if (!dp[i][j][l]) {
                        dp[i][j][k] = true;
                        break;
                    }
                }
                if (!dp[i][j][k] && i && j && k && i <= j && j <= k) cout << i << " " << j << " " << k << "\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++){
        // cout << "Case #" << i << ": ";
        // cerr << "Case #" << i << ": \n";
        Solve();
    }

    return 0;
}