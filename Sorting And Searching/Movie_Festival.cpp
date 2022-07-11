#include<bits/stdc++.h>
using namespace std;
 
bool cmp(pair<int, int> &u, pair<int, int> &v){
    return u.second < v.second;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (pair<int, int> &x: a) cin >> x.first >> x.second;
    sort(a.begin(), a.end(), cmp);
    int ans = 0, last = 0;
    for (pair<int, int> &x: a){
        if (x.first >= last){
            ans++;
            last = x.second;
        }
    }
    cout << ans << "\n";
 
    return 0;
}