#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    vector<int> loc(n + 1);
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        loc[x] = i;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++){
        if (loc[i] < loc[i - 1]) ans++;
    }
    cout << ans << "\n";
 
    return 0;
}