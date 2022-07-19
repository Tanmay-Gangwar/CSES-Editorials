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
int res;

void dfs(int i, int j){
    if (visited[i][j] || grid[i][j] == '#') return;
    visited[i][j] = true;
    if (i > 0) dfs(i - 1, j);
    if (j > 0) dfs(i, j - 1);
    if (i < n - 1) dfs(i + 1, j);
    if (j < m - 1) dfs(i, j + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }
    res = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == '.' && !visited[i][j]){
                res++;
                dfs(i, j);
            }
        }
    }
    cout << res;


    return 0;
}