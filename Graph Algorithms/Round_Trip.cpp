#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

ll n, m;
vector<vector<ll>> adj;
vector<bool> visited;
vector<ll> path;

bool dfs(ll x, ll from){
    if (visited[x]){
        ll cnt = 2;
        string res = "";
        res += to_string(x) + " ";
        while (from != x){
            cnt++;
            res += to_string(from) + " ";
            from = path[from];
        }
        res += to_string(x);
        cout << cnt << "\n";
        cout << res << "\n";
        return true;
    }
    visited[x] = true;
    path[x] = from;
    for (ll y: adj[x]){
        if (y != from) {
            if (dfs(y, x)) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    adj = vector<vector<ll>>(n + 1);
    visited = vector<bool>(n + 1);
    path = vector<ll>(n + 1);   
    for (ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    } 
    for (ll i = 1; i <= n; i++){
        if (!visited[i]){
            if (dfs(i, i)) return 0;
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}