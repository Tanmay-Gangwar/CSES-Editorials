#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    multiset<int> a;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        auto it = a.upper_bound(x);
        if (it != a.end()) a.erase(it);
        a.insert(x);
    }
    cout << a.size() << "\n";
 
    return 0;
}