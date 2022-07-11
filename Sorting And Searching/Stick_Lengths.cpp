#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    sort(a.begin(), a.end());
    long long ans = 0;
    int mid = a[n >> 1];
    for (int x: a) ans += abs(x - mid);
    cout << ans << "\n";
 
    return 0;
}