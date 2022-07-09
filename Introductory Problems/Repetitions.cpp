#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    string s;
    cin >> s;
    int maxStreak = 1, streak = 1;
    for (int i = 1; i < (int) s.length(); i++){
        if (s[i] == s[i - 1]) streak++;
        else streak = 1;
        maxStreak = max(maxStreak, streak);
    }
    cout << maxStreak << "\n";
 
    return 0;
}