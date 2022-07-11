#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0, j = n - 1; i <= j; j--){
        if (a[i] + a[j] <= x) i++;
        ans++;
    }
    cout << ans << "\n";
 
    return 0;
}