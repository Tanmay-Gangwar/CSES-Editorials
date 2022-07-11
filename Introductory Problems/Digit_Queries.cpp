#include<bits/stdc++.h>
using namespace std;
 
long long num[19];
 
long long location(long long x){
    long long d = to_string(x).length();
    long long pos = d * x - num[d];
    return pos;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int q;
    cin >> q;
    num[0] = 0;
    for (int i = 1; i <= 18; i++) num[i] = 10 * num[i - 1] + 1;
    while (q--){
        long long k;
        cin >> k;
        long long l = 0, r = k + 1;
        while (r - l > 1){
            long long m = (l + r) / 2;
            if (location(m) < k) l = m;
            else r = m;
        }
        long long index = k - location(l) - 1;
        cout << to_string(l)[index] << "\n";
    }
 
    return 0;
}