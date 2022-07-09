#include<bits/stdc++.h>
using namespace std; 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    long ans = (long) n * (n + 1) / 2;
    while (--n) {
        int x;
        cin >> x;
        ans -= x;
    }
    cout << ans << "\n";
    
    return 0;
}