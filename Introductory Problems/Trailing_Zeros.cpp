#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    int ans = 0;
    while (n){
        n /= 5;
        ans += n;
    }
    cout << ans << "\n";
 
    return 0;
}