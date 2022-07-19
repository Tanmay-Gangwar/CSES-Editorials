#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

ll n, m;
vector<vector<char>> grid, from;
vector<pair<ll, ll>> playerPos, monsterPos;
vector<vector<bool>> safe, visited;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll startR, startC;
    cin >> n >> m;
    grid = vector<vector<char>>(n, vector<char>(m));
    from = vector<vector<char>>(n, vector<char>(m));
    safe = vector<vector<bool>>(n, vector<bool>(m, true));
    visited = vector<vector<bool>>(n, vector<bool>(m));
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') startR = i, startC = j, playerPos.push_back({i, j});
            else if (grid[i][j] == 'M') {
                monsterPos.push_back({i, j});
                safe[i][j] = false;
            }
        }
    }
    if ((startR == n - 1 || startR == 0) && (startC == m - 1 || startC == 0)){
        cout << "YES\n0\n";
        return 0;
    }
    ll r = -1, c = -1;
    while (true){
        vector<pair<ll, ll>> temp;
        for (pair<ll, ll> pos: monsterPos){
            ll i = pos.first;
            ll j = pos.second;
            if (i > 0 && grid[i - 1][j] != '#' && safe[i - 1][j]) safe[i - 1][j] = false, temp.push_back({i - 1, j});
            if (j > 0 && grid[i][j - 1] != '#' && safe[i][j - 1]) safe[i][j - 1] = false, temp.push_back({i, j - 1});
            if (i < n - 1 && grid[i + 1][j] != '#' && safe[i + 1][j]) safe[i + 1][j] = false, temp.push_back({i + 1, j});
            if (j < m - 1 && grid[i][j + 1] != '#' && safe[i][j + 1]) safe[i][j + 1] = false, temp.push_back({i, j + 1});
        }
        monsterPos = temp;

        temp = vector<pair<ll, ll>>();
        for (pair<ll, ll> pos: playerPos){
            ll i = pos.first;
            ll j = pos.second;
            visited[i][j] = true;
            if (i > 0 && grid[i - 1][j] != '#' && !visited[i - 1][j] && safe[i - 1][j]) {
                temp.push_back({i - 1, j}), from[i - 1][j] = 'U';
                if (i - 1 == 0) {
                    r = i - 1;
                    c = j;
                    break;
                }
            }
            if (j > 0 && grid[i][j - 1] != '#' && !visited[i][j - 1] && safe[i][j - 1]) {
                temp.push_back({i, j - 1}), from[i][j - 1] = 'L';
                if (j - 1 == 0){
                    r = i;
                    c = j - 1;
                    break;
                }
            }
            if (i < n - 1 && grid[i + 1][j] != '#' && !visited[i + 1][j] && safe[i + 1][j]) {
                temp.push_back({i + 1, j}), from[i + 1][j] = 'D';
                if (i + 1 == n - 1){
                    r = i + 1;
                    c = j;
                    break;
                }
            }
            if (j < m - 1 && grid[i][j + 1] != '#' && !visited[i][j + 1] && safe[i][j + 1]) {
                temp.push_back({i, j + 1}), from[i][j + 1] = 'R';
                if (j + 1 == m - 1){
                    r = i;
                    c = j + 1;
                    break;
                }
            }
        }
        if (temp.empty()) break;
        playerPos = temp;
    }
    if (r == -1){
        cout << "NO\n";
        return 0;
    }
    string s = "";
    while (r != startR || c != startC){
        s += from[r][c];
        if (from[r][c] == 'L') c++;
        else if (from[r][c] == 'R') c--;
        else if (from[r][c] == 'U') r++;
        else r--;
    }
    cout << "YES\n";
    cout << s.length() << "\n";
    reverse(s.begin(), s.end());
    cout << s << "\n";

    return 0;
}