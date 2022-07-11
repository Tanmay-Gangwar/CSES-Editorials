#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int x, n;
    cin >> x >> n;
    set<int> loc;
    multiset<int> length;
    loc.insert(0);
    loc.insert(x);
    length.insert(x);
    while (n--){
        int z;
        cin >> z;
        loc.insert(z);
        int i = *(--loc.lower_bound(z));
        int j = *(loc.upper_bound(z));
        length.erase(length.find(j - i));
        length.insert(j - z);
        length.insert(z - i);
        cout << *(--length.end()) << " ";
    }
 
    return 0;
}