#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

ll n;
vector<set<ll>> adj;
set<ll> leaves;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    adj = vector<set<ll>>(n + 1);
    for (ll i = 1; i < n; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    for (ll i = 1; i <= n; i++){
        if ((int)adj[i].size() == 1) leaves.insert(i);
    }
    ll ans = 0;
    while (!leaves.empty()){
        auto it = leaves.begin();
        ll x = *it;
        leaves.erase(it);
        auto iit = adj[x].begin();
        ll y = *iit;
        adj[x].erase(iit);
        adj[y].erase(x);
        if ((int) adj[y].size() == 0) leaves.erase(y);
        for (ll z: adj[y]){
            adj[z].erase(y);
            if ((int)adj[z].size() == 0) leaves.erase(z);
            else if ((int)adj[z].size() == 1) leaves.insert(z);
        }
        adj[y].clear();
        ans++;
    }
    cout << ans << "\n";

    return 0;
}