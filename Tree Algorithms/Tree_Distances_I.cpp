#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

ll n;
vector<vector<ll>> adj;
map<pair<ll, ll>, ll> maxD;

ll dfs1(ll i, ll from){
    ll ans = 0;
    for (ll x: adj[i]){
        if (x == from) continue;
        ans = max(ans, dfs(x, i) + 1);
    }
    maxD[{from, i}] = ans;
    return ans;
}

ll dfs2(ll i, ll from, ll res = 1){
    maxD[{i, from}] = res;
    for (ll x: adj[i]){
        if (x == from) continue;
        dfs2(x, i, res + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    adj = vector<vector<ll>>(n + 1);
    for (ll i = 1; i < n; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (ll i = 1; i <= n; i++){
        ll ans = 0;
        for (ll x: adj[i]){
            ans = max(ans, getMaxD(x, i) + 1);
        }
        cout << ans << " ";
    }

    return 0;
}