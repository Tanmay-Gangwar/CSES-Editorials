#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    long long ans = -1e9, sum = 0, mn = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        sum += x;
        ans = max(ans, sum - mn);
        mn = min(mn, sum);
    }
    cout << ans << "\n";
 
    return 0;
}