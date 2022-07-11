#include<bits/stdc++.h>
using namespace std;
 
bool cmp(pair<int, int> &a, pair<int, int> &b){
    return (a.first < b.first || (a.first == b.first && a.second > b.second));
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    map<pair<int, int>, int> loc;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        loc[a[i]] = i;
    }
    sort(a.begin(), a.end(), cmp);
    // sort(a.begin(), a.end());
    set<int> b;
    vector<int> result(n);
    for (int i = n - 1; i >= 0; i--){
        auto it = b.upper_bound(a[i].second);
        result[loc[a[i]]] = (int)(it != b.begin());
        b.insert(a[i].second);
    }
    for (int &x: result) cout << x << " ";
    cout << "\n";
 
    b.clear();
    for (int i = 0; i < n; i++){
        auto it = b.lower_bound(a[i].second);
        result[loc[a[i]]] = (int)(it != b.end());
        b.insert(a[i].second);
    }       
    for (int &x: result) cout << x << " ";
    cout << "\n";
 
    return 0;
}