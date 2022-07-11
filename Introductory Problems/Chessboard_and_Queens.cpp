#include<bits/stdc++.h>
using namespace std;
 
int ans = 0;
char board[8][8];
 
bool valid(int row, int col){
    if (board[row][col] == '*') return false;
    for (int i = 1; i <= row; i++){
        if (board[row - i][col] == 'Q') return false;
        if (col >= i && board[row - i][col - i] == 'Q') return false;
        if (col + i < 8 && board[row - i][col + i] == 'Q') return false;
    }
    return true;
}
 
void solve(int row){
    if (row == 8){
        ans++;
        return;
    }
    for (int col = 0; col < 8; col++){
        if (valid(row, col)){
            board[row][col] = 'Q';
            solve(row + 1);
            board[row][col] = '.';
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++) cin >> board[i][j];
    }
    solve(0);
    cout << ans << "\n";
 
    return 0;
}