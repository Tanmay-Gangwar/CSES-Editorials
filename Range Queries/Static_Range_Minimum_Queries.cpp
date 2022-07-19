#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

struct SparseOp{
    ll operator()(ll u, ll v){
        return min(u, v);
    }
};

template<class T, class Op = SparseOp>
class SparseTable{
    public:
    vector<vector<T>> table;
    Op op;

    SparseTable(){}

    void build(vector<T> a){
        int n = a.size();
        int height = 32 - __builtin_clz(n);
        table.resize(n, vector<T>(height));
        for (int i = 0; i < n; i++) table[i][0] = a[i];
        for (int j = 1; j < height; j++){
            for (int i = 0; i + (1 << (j - 1)) < n; i++){
                table[i][j] = op(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r){
        int len = r - l + 1;
        int depth = 31 - __builtin_clz(len);
        return op(table[l][depth], table[r - (1 << depth) + 1][depth]);
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) cin >> a[i];
    SparseTable<ll> table;
    table.build(a);
    while (q--){
        ll l, r;
        cin >> l >> r;
        cout << table.query(l, r) << "\n";
    }


    return 0;
}