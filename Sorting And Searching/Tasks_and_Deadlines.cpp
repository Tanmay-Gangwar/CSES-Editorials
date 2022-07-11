#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (pair<int, int> &x: a) cin >> x.first >> x.second;
    sort(a.begin(), a.end());
    long long ans = 0, total = 0;
    for (pair<int, int> &x: a){
        total += x.first;
        ans += x.second - total;
    }    
    cout << ans << "\n";
 
    return 0;
}