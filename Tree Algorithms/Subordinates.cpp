#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

ll n;
vector<ll> size;
vector<vector<ll>> children;

void dfs(ll x){
    size[x] = 1;
    for (ll y: children[x]){
        dfs(y);
        size[x] += size[y];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    children = vector<vector<ll>>(n + 1);
    size = vector<ll>(n + 1);
    for (ll i = 2; i <= n; i++){
        ll x;
        cin >> x;
        children[x].push_back(i);
    }
    dfs(1);
    for (ll i = 1; i <= n; i++) cout << size[i] - 1 << " ";

    return 0;
}