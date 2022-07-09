#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    long sum = (long) n * (n + 1) / 2;
    if (sum & 1){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    sum >>= 1;
    cout << n / 2 << "\n";
    int x = 1 - (n & 1), i;
    long total;
    for (total = 0, i = 0; total < sum; total += n + x, i++){
        if (i + x) cout << i + x << " ";
        cout << n - i << " ";
    }
    cout << "\n" << (n + 1) / 2 << "\n";
    for (total = 0; total < sum; total += n + x, i++){
        cout << i + x << " " << n - i << " ";
    }
 
    return 0;
}
