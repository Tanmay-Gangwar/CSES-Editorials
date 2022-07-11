#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
 
bool cmp(pair<int, int> &a, pair<int, int> &b){
    return (a.first < b.first || (a.first == b.first && a.second > b.second));
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    map<pair<int, int>, int> loc;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        loc[a[i]] = i;
    }
    sort(a.begin(), a.end(), cmp);
    ordered_set<pair<int, int>> b;
    vector<int> result(n);
    for (int i = n - 1; i >= 0; i--){
        result[loc[a[i]]] = b.order_of_key({a[i].second, n + 1});
        b.insert({a[i].second, i});
    }
    for (int &x: result) cout << x << " ";
    cout << "\n";
 
    b.clear();
    for (int i = 0; i < n; i++){
        result[loc[a[i]]] = b.size() - b.order_of_key({a[i].second, -1});
        b.insert({a[i].second, i});
    }       
    for (int &x: result) cout << x << " ";
    cout << "\n";
 
    return 0;
}