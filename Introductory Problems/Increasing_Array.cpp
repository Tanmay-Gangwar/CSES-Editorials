#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, prev = 0;
    long ans = 0;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x > prev) prev = x;     
        else ans += prev - x;
    }
    cout << ans << "\n";
 
    return 0;
}