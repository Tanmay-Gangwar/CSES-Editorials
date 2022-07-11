#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    map<int, vector<pair<int, int>>> loc;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (loc.find(x - a[i] - a[j]) != loc.end()){
                for (pair<int, int> z: loc[x - a[i] - a[j]]){
                    if (z.first != i && z.first != j && z.second != i && z.second != j){
                        cout << z.first + 1 << " " << z.second + 1 << " " << i + 1 << " " << j + 1 << "\n";
                        return 0;
                    }
                }
            }
            loc[a[i] + a[j]].push_back({i, j});
        }
    }
    cout << "IMPOSSIBLE\n";
 
    return 0;
}