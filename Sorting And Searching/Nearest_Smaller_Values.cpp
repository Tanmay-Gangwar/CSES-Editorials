#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    stack<int> stk;
    stk.push(0);
    for (int i = 1; i <= n; i++){
        while (a[stk.top()] >= a[i]) stk.pop();
        cout << stk.top() << " ";
        stk.push(i);
    }
 
    return 0;
}