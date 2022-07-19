#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

ll inf = 1e18;
vector<vector<ll>> adj;
vector<ll> dist;
vector<bool> visited;

bool dfs(ll x, set<ll> &invalid){
    if (visited[x]) return false;
    if (dist[x] != -inf && invalid.find(x) != invalid.end()) return true;
    visited[x] = true;
    for (ll y: adj[x]){
        if (dfs(y, invalid)) return true;
    }
    return false;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll n, m;
    cin >> n >> m;
    visited = vector<bool>(n + 1);
    adj = vector<vector<ll>>(n + 1);
    dist = vector<ll>(n + 1, -inf);
    vector<array<ll, 3>> edges(m);
    for (array<ll, 3> &x: edges){
        cin >> x[0] >> x[1] >> x[2];
        adj[x[1]].push_back(x[0]);
    }
    dist[1] = 0;
    for (ll tt = 1; tt < n; tt++){
        for (array<ll, 3> &x: edges){
            if (dist[x[0]] > -inf) dist[x[1]] = max(dist[x[1]], dist[x[0]] + x[2]);
        }
    }
    set<ll> invalid;
    for (array<ll, 3> &x: edges){
        if (dist[x[1]] < dist[x[0]] + x[2]) invalid.insert(x[1]);
    }
    if (dfs(n, invalid) || dist[n] == inf) cout << "-1\n";
    else cout << dist[n] << "\n";
 
    return 0;
}