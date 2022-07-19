#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

ll n, m;
vector<vector<pair<ll, ll>>> adj;
vector<ll> dist;
set<pair<ll, ll>> toVisit;
vector<bool> visited;

void dijkstra(ll i){
    toVisit.insert({0, i});
    while (!toVisit.empty()){
        auto it = toVisit.begin();
        i = it->second;
        ll d = it->first;
        toVisit.erase(it);
        if (visited[it->second]) continue;
        visited[it->second] = true;
        dist[it->second] = it->first;
        for (pair<ll, ll> x: adj[it->second]){
            if (!visited[x.first]) toVisit.insert({x.second + d, x.first});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    adj = vector<vector<pair<ll, ll>>>(n + 1);
    dist = vector<ll>(n + 1);
    visited = vector<bool>(n + 1);
    for (ll i = 0; i < m; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].emplace_back(y, z);
    }
    dijkstra(1);
    for (ll i = 1; i <= n; i++) cout << dist[i] << " ";

    return 0;
}