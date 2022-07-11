#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0, j = 0; i < n && j < m;){
        if (a[i] - k > b[j]) j++;
        else if (a[i] + k < b[j]) i++;
        else{
            ans++;
            i++;
            j++;
        }
    }
    cout << ans << "\n";
 
    return 0;
}