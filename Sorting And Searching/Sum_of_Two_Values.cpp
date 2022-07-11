#include<bits/stdc++.h>
using namespace std; 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    map<int, int> loc;
    for (int i = 0; i < n; i++){
        if (loc.find(k - a[i]) != loc.end()){
            cout << loc[k - a[i]] << " " << i + 1 << "\n";
            return 0;
        }
        loc[a[i]] = i + 1;
    }
    cout << "IMPOSSIBLE\n";
 
    return 0;
}