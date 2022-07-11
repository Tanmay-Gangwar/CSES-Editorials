#include<bits/stdc++.h>
using namespace std;
 
string s;
int ans = 0;
bool visited[9][9];
 
void solve(int index, int i, int j){
    if (visited[i][j]) return;
    if (i == 7 && j == 1 && index == 48) ans++;
    if (i == 7 && j == 1) return;
    if (index == 48) return;
    if (visited[i + 1][j] && visited[i - 1][j] && !visited[i][j + 1] && !visited[i][j - 1]) return;
    if (visited[i][j + 1] && visited[i][j - 1] && !visited[i + 1][j] && !visited[i - 1][j]) return;
    visited[i][j] = true;
    if (s[index] == '?' || s[index] == 'R') solve(index + 1, i, j + 1);
    if (s[index] == '?' || s[index] == 'L') solve(index + 1, i, j - 1);
    if (s[index] == '?' || s[index] == 'D') solve(index + 1, i + 1, j);
    if (s[index] == '?' || s[index] == 'U') solve(index + 1, i - 1, j);
    visited[i][j] = false;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> s;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (i == 0 || i == 8 || j == 0 || j == 8) visited[i][j] = true;
            else visited[i][j] = false;
        }
    }
    solve(0, 1, 1);
    cout << ans << "\n";
 
    return 0;
}