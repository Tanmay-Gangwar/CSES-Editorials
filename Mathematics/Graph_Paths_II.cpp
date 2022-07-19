#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

vector<vector<ll>> operator*(vector<vector<ll>> a, vector<vector<ll>> b){
    ll n = a.size();
    vector<vector<ll>> ans(n, vector<ll>(n, -1));
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < n; j++){
            for (ll k = 0; k < n; k++){
                if (a[i][k] != -1 && b[k][j] != -1) {
                    if (ans[i][j] == -1) ans[i][j] = a[i][k] + b[k][j];
                    else ans[i][j] = min(ans[i][j], a[i][k] + b[k][j]);
                }
            }
        }
    }
    return ans;
}

template<class T>
T power(T a, ll n){
    T ans = a;
    n--;
    while (n){
        if (n & 1) ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, -1));
    for (ll i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if (adj[a][b] == -1) adj[a][b] = c;
        else adj[a][b] = min(adj[a][b], c);
    }
    adj = power(adj, k);
    cout << adj[1][n] << "\n";

    return 0;
}