#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        if ((a + b) % 3) cout << "NO\n";
        else if (a > 2 * b || b > 2 * a) cout << "NO\n";
        else cout << "YES\n";
    }
 
    return 0;
}