#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m, inf = 1e18;
    cin >> n >> m;
    vector<array<ll, 3>> edges(m);
    for (array<ll, 3> &x: edges) cin >> x[0] >> x[1] >> x[2];
    vector<ll> dist(n + 1, inf), from(n + 1, -1);
    dist[1] = 0;
    ll neg;
    for (ll tt = 0; tt < n; tt++){
        neg = -1;
        for (array<ll, 3> &x: edges){
            if (dist[x[0]] + x[2] < dist[x[1]]) {
                dist[x[1]] = dist[x[0]] + x[2];
                from[x[1]] = x[0];
                neg = x[1];
            }
        }
    }    
    if (neg == -1) cout << "NO\n";
    else{
        ll x = neg;
        for (ll i = 0; i < n; i++) x = from[x];
        vector<ll> path;
        for (ll curr = x; curr != x || path.size() < 1; curr = from[curr]) path.push_back(curr);
        path.push_back(x);
        reverse(path.begin(), path.end());
        cout << "YES\n";
        for (ll x: path) cout << x << " "; cout << "\n";
    }

    return 0;
}