#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    map<long long, int> cnt;
    cnt[0]++;
    vector<long long> a(n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
        ans += cnt[(a[i] % n + n) % n]++;
    }
    cout << ans << "\n";
 
    return 0;
}