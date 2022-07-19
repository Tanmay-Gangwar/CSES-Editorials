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
vector<vector<ll>> ancestor;

void buildAncestors(vector<ll> parent){
    ll n = parent.size();
    ancestor = vector<vector<ll>>();
    ancestor.push_back(parent);
    for (ll p = 1; (1ll << p) < n; p++){
        ancestor.push_back(vector<ll>(n));
        for (ll i = 0; i < n; i++){
            if (ancestor[p - 1][i] >= 0 && ancestor[p - 1][i] < n) ancestor[p][i] = ancestor[p - 1][ancestor[p - 1][i]];
            else ancestor[p][i] = -1;
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    

    return 0;
}