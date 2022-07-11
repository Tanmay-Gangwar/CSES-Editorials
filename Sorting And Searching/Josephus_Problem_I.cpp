#include<bits/stdc++.h>
using namespace std; 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
    while (!q.empty()){
        q.push(q.front());
        q.pop();
        cout << q.front() << " ";
        q.pop();
    }
 
    return 0;
}