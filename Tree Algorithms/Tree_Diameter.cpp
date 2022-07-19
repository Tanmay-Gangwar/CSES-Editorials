#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

ll n, diameter = 0;
vector<vector<ll>> adj;

ll dfs(ll i, ll from){
    vector<ll> depths(2);
    for (ll x: adj[i]){
        if (x == from) continue;
        depths.push_back(dfs(x, i));
    }
    sort(depths.rbegin(), depths.rend());
    diameter = max(depths[0] + depths[1] + 1, diameter);
    return depths[0] + 1;
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
    dfs(1, 1);
    cout << diameter - 1 << "\n";

    return 0;
}