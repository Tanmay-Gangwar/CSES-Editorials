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
vector<ll> team;

bool dfs(ll x, ll i){
    if (team[x]) return team[x] == i;
    team[x] = i;
    for (ll y: adj[x]){
        if (!dfs(y, 3 - i)) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    adj = vector<vector<ll>>(n + 1);
    team = vector<ll>(n + 1);
    for (ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (ll i = 1; i <= n; i++){
        if (team[i] == 0) {
            if (!dfs(i, 1)){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for (ll i = 1; i <= n; i++) cout << team[i] << " ";

    return 0;
}