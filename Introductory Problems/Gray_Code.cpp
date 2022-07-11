#include<bits/stdc++.h>
using namespace std;
 
void print(int n, int length){
    string res = "";
    while (n){
        res += (char)((n & 1) + '0');
        n >>= 1;
    }
    while (res.length() < length) res += '0';
    reverse(res.begin(), res.end());
    cout << res << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    for (int i = 0; i < (1ll << n); i++){
        print(i ^ (i >> 1), n);
    }    
 
    return 0;
}