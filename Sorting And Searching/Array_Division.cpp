#include<bits/stdc++.h>
using namespace std;
 
bool possible(const vector<int> &a, int n, int k, long long s){
    int cnt = 1;
    long long sum = 0;
    for (int x: a){
        if (sum + x > s){
            sum = x;
            cnt++;
        }
        else sum += x;
    }
    return cnt <= k;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long l = 0, r = 0;
    for (int &x: a) {
        cin >> x;
        r += x;
        l = max(l, (long long) x - 1);
    }
    while (r - l > 1){
        long long m = (l + r) / 2;
        if (possible(a, n, k, m)) r = m;
        else l = m;
    }
    cout << r << "\n";
 
 
    return 0;
}