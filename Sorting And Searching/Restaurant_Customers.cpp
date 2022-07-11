#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    vector<int> in(n), out(n);
    for (int i = 0; i < n; i++) cin >> in[i] >> out[i];
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());
    int ans = 0, curr = 0;
    for (int i = 0, j = 0; i < n && j < n;){
        if (in[i] < out[j]){
            curr++;
            i++;
        }
        else{
            curr--;
            j++;
        }
        ans = max(ans, curr);
    }
    cout << ans << "\n";
 
    return 0;
}