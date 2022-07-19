#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

int n, m;
char grid[1000][1000];
bool visited[1000][1000];
char path[1000][1000];

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()){
        pair<int, int> pos = q.front();
        i = pos.first;
        j = pos.second;
        q.pop();
        if (i > 0 && grid[i - 1][j] != '#' && !visited[i - 1][j]){
            q.push({i - 1, j});
            path[i - 1][j] = 'D';
            visited[i - 1][j] = true;
        }
        if (j > 0 && grid[i][j - 1] != '#' && !visited[i][j - 1]){
            q.push({i, j - 1});
            path[i][j - 1] = 'R';
            visited[i][j - 1] = true;
        }
        if (i < n - 1 && grid[i + 1][j] != '#' && !visited[i + 1][j]){
            q.push({i + 1, j});
            path[i + 1][j] = 'U';
            visited[i + 1][j] = true;
        }
        if (j < m - 1 && grid[i][j + 1] != '#' && !visited[i][j + 1]){
            q.push({i, j + 1});
            path[i][j + 1] = 'L';
            visited[i][j + 1] = true;
        }
    }
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int r, c;
    int x, y;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            visited[i][j] = false;
            path[i][j] = '#';
            if (grid[i][j] == 'B') r = i, c = j;
            if (grid[i][j] == 'A') y = i, x = j;
        }
    }
    visited[r][c] = true;
    bfs(r, c);
    if (path[y][x] == '#') cout << "NO\n";
    else{
        cout << "YES\n";
        string res = "";
        while (grid[y][x] != 'B'){
            res += path[y][x];
            if (path[y][x] == 'L') x--;
            else if (path[y][x] == 'R') x++;
            else if (path[y][x] == 'U') y--;
            else y++;
        }
        cout << res.length() << "\n";
        cout << res << "\n";
    }


    return 0;
}