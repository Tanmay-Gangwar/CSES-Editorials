#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    ordered_set<pair<int, int>> b;
    for (int i = 0; i < k - 1; i++) b.insert({a[i], i});
    for (int i = k - 1; i < n; i++){
        b.insert({a[i], i});
        auto it = b.find_by_order((k - 1) / 2);
        cout << it->first << " ";
        b.erase({a[i - k + 1], i - k + 1});
    }
 
    return 0;
}