#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, mx = 0;
    cin >> n;
    long sum = 0;
    while (n--){
        int x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }
    sum -= mx;
    cout << max(sum, (long)mx) + mx << "\n";
 
    return 0;
}