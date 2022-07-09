#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
    while (t--){
        long c, r;
        cin >> r >> c;
        if (c > r){
            if (c & 1) cout << c * c - r + 1 << "\n";
            else cout << (c - 1) * (c - 1) + r << "\n";
        }
        else{
            if (r & 1) cout << (r - 1) * (r - 1) + c << "\n";
            else cout << r * r - c + 1 << "\n";
        }
    }
 
    return 0;
}