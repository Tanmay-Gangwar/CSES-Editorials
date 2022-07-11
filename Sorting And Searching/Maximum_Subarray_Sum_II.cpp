#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> prefix(n + 1);
    set<pair<long long, int>> st;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }
    long long ans = -1e18;
    for (int i = a; i <= n; i++){
        st.insert({prefix[i - a], i - a});
        auto it = st.begin();
        ans = max(ans, prefix[i] - it->first);
        if (i >= b) st.erase({prefix[i - b], i - b});
    }
    cout << ans << "\n";
 
    return 0;
}