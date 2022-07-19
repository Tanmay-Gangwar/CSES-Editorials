#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

vector<ll> dijkstra(ll i, ll n, vector<vector<pair<ll, ll>>> &adj){
    vector<ll> dist(n + 1, 1e18);
    set<pair<ll, ll>> toVisit;
    vector<bool> visited(n + 1);
    toVisit.insert({0, i});
    while (!toVisit.empty()){
        auto it = toVisit.begin();
        ll d = it->first;
        i = it->second;
        toVisit.erase(it);
        if (visited[i]) continue;
        visited[i] = true;
        dist[i] = d;
        for (pair<ll, ll> x: adj[i]){
            toVisit.insert({x.second + d, x.first});
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj1(n + 1), adjn(n + 1);
    for (ll i = 0; i < m; i++){
        ll x, y, w;
        cin >> x >> y >> w;
        adj1[x].emplace_back(y, w);
        adjn[y].emplace_back(x, w);
    }
    vector<ll> dist1 = dijkstra(1, n, adj1);
    vector<ll> distn = dijkstra(n, n, adjn);
    ll ans = 1e18;
    for (ll i = 1; i <= n; i++){
        for (pair<ll, ll> x: adj1[i]){
            ans = min(ans, dist1[i] + x.second / 2 + distn[x.first]);
        }
    }
    cout << ans << "\n";

    return 0;
}