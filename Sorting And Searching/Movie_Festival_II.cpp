#include<bits/stdc++.h>
using namespace std;
 
bool cmp(pair<int, int> &x, pair<int, int> &y){
    return x.second < y.second;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int k, n;
    cin >> k >> n;
    vector<pair<int, int>> a(k);
    multiset<int> freetime;
    for (pair<int, int> &x: a) cin >> x.first >> x.second;
    for (int i = 0; i < n; i++) freetime.insert(0);
    sort(a.begin(), a.end(), cmp);
    int ans = 0;
    for (pair<int, int> &x: a){
        auto it = freetime.upper_bound(x.first);
        if (it != freetime.begin()){
            --it;
            ans++;
            freetime.erase(it);
            freetime.insert(x.second);
        }
    }
    cout << ans << "\n";
 
    return 0;
}