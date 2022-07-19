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

void bfs(ll x){
    queue<ll> q;
    q.push(x);
    visited[x] = true;
    while (!q.empty()){
        x = q.front();
        q.pop();
        for (ll y: adj[x]){
            if (!visited[y]){
                path[y] = x;
                visited[y] = true;
                q.push(y);
            }
        }
    }
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
    bfs(n);
    if (path[1]){
        string res = "1 ";
        ll ans = 1;
        ll x = 1;
        while (x != n){
            res += to_string(path[x]) + " ";
            ans++;
            x = path[x];
        }
        cout << ans << "\n" << res << "\n";
    }
    else cout << "IMPOSSIBLE";

    return 0;
}