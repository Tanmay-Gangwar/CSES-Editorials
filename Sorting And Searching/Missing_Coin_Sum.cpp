#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    sort(a.begin(), a.end());
    int ans = 1;
    for (int x: a){
        if (x > ans) break;
        ans += x;
    }
    cout << ans << "\n";
 
    return 0;
}
