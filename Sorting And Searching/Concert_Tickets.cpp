#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    multiset<int> a;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.insert(x);
    }
    while (m--){
        int x;
        cin >> x;
        auto it = a.upper_bound(x);
        if (it == a.begin()) cout << "-1\n";
        else{
            --it;
            cout << *it << "\n";
            a.erase(it);
        }
    }
 
    return 0;
}