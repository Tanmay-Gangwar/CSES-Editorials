#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, x;
    cin >> n >> x;
    vector<long long> a(n + 1);
    map<long long, int> cnt;
    cnt[0]++;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
        ans += cnt[a[i] - x];
        cnt[a[i]]++;
    }
    cout << ans << "\n";
 
    return 0;
}