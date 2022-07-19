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
vector<ll> component;
vector<bool> visited;

void dfs(ll x){
    if (visited[x]) return;
    visited[x] = true;
    for (ll y: adj[x]) dfs(y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    adj = vector<vector<ll>>(n + 1);
    component = vector<ll>();
    visited = vector<bool>(n + 1);
    for (ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    for (ll i = 1; i <= n; i++){
        if (!visited[i]){
            component.push_back(i);
            dfs(i);
        }
    }
    cout << (component.size() - 1) << "\n";
    for (ll i = 1; i < component.size(); i++){
        cout << component[i - 1] << " " << component[i] << "\n";
    }


    return 0;
}