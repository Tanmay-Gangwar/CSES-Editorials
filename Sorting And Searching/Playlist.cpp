#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    map<int, bool> played;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int ans = 0;
    for (int i = 0, j = 0; j < n; j++){
        while (played[a[j]]){
            played[a[i]] = false;
            i++;
        }
        played[a[j]] = true;
        ans = max(ans, j - i + 1);
    }
    cout << ans << "\n";
 
    return 0;
}