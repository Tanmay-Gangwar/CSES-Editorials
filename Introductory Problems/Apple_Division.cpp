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
    long ans = 1e9;
    for (int i = 0; i < (1 << n); i++){
        long alpha = 0, beta = 0;
        for (int bit = 0; bit < n; bit++){
            if ((1 << bit) & i) alpha += a[bit];
            else beta += a[bit];
        }
        ans = min(ans, abs(alpha - beta));
    }
    cout << ans << "\n";
 
    return 0;
}