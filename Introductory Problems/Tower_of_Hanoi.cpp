#include<bits/stdc++.h>
using namespace std;
 
void solve(int n, int from, int to, int helper){
    if (n == 0) return;
    solve(n - 1, from, helper, to);
    cout << from << " " << to << "\n";
    solve(n - 1, helper, to, from);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    solve(n, 1, 3, 2);
 
    return 0;
}