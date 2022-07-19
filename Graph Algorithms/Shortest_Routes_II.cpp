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

    ll n, m, q, inf = 1e18;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, inf));
    for (ll i = 0; i < m; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        dist[x][y] = min(dist[x][y], z);
        dist[y][x] = min(dist[y][x], z);
    }
    for (ll i = 1; i <= n; i++) dist[i][i] = 0;

    for (ll k = 1; k <= n; k++){
        for (ll i = 1; i <= n; i++){
            for (ll j = 1; j <= n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    while (q--){
        ll x, y;
        cin >> x >> y;
        if (dist[x][y] == inf) cout << "-1\n";
        else cout << dist[x][y] << "\n";
    }

    return 0;
}