#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2), loc(n + 2);
    loc[n + 1] = n + 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        loc[a[i]] = i;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++){
        if (loc[i] < loc[i - 1]) ans++;
    }
    while (m--){
        int i, j;
        cin >> i >> j;
        int x = a[i], y = a[j];
        if (x > y) swap(x, y);
        if (loc[x] < loc[x - 1]) ans--;
        if (loc[x + 1] < loc[x]) ans--;
        if (x != y - 1 && loc[y] < loc[y - 1]) ans--;
        if (loc[y + 1] < loc[y]) ans--;
        swap(a[i], a[j]);
        loc[a[i]] = i;
        loc[a[j]] = j;
        x = a[i], y = a[j];
        if (x > y) swap(x, y);
        if (loc[x] < loc[x - 1]) ans++;
        if (loc[x + 1] < loc[x]) ans++;
        if (x != y - 1 && loc[y] < loc[y - 1]) ans++;
        if (loc[y + 1] < loc[y]) ans++;
        cout << ans << "\n";
    }
 
    return 0;
}