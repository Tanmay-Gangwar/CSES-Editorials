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
    ordered_set<int> a;
    for (int i = 1; i <= n; i++) a.insert(i);
    int i = 0;
    while (!a.empty()){
        i = (i + k) % (int)a.size();
        auto it = a.find_by_order(i);
        cout << *it << " ";
        a.erase(it);
    }
 
    return 0;
}