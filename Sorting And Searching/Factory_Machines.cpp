#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    long long l = 0, r = 1e18;
    while (r - l > 1){
        long long m = (l + r) / 2;
        long long cnt = 0;
        for (int x: a) {
            cnt += m / x;
            if (cnt >= t) break;
        }
        if (cnt >= t) r = m;
        else l = m;
    }
    cout << r << "\n";
 
    return 0;
}