#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    vector<int> a(n);
    int curr = 0;
    long long ans = 0;
    for (int i = 0, j = 0; i < n; i++){
        cin >> a[i];
        if (cnt[a[i]]++ == 0) curr++;
        for (; curr > k; j++){
            if (--cnt[a[j]] == 0) curr--;
        }
        ans += i - j + 1;
    }
    cout << ans << "\n";
 
    return 0;
}