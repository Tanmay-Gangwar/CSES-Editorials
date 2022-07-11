#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());
    vector<int> ans(n);
    set<pair<int, int>> rooms;
    int cnt = 0;
    for (array<int, 3> &ar: a){
        auto it = rooms.lower_bound({ar[0], -1});
        if (it == rooms.begin()){
            cnt++;
            ans[ar[2]] = cnt;
        }
        else{
            --it;
            ans[ar[2]] = it->second;
            rooms.erase(it);
        }
        rooms.insert({ar[1], ans[ar[2]]});
    }
    cout << cnt << "\n";
    for (int x: ans) cout << x << " ";
 
    return 0;
}