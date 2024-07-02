#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    int n, m;

    void dfs(vector<vector<char> >& grid, int x, int y){
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx == m || ny == n || grid[nx][ny] != 'O') continue;

            grid[nx][ny] = '1';
            dfs(grid, nx, ny);
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i<m; i++){
            if(board[i][0] == 'O'){
                board[i][0] = '1';
                dfs(board, i, 0);
            }
            if(board[i][n-1] == 'O'){
                board[i][n-1] = '1';
                dfs(board, i, n-1);
            }
        }
        for(int j = 0; j<n; j++){
            if(board[0][j] == 'O'){
                board[0][j] = '1';
                dfs(board, 0, j);
            }
            if(board[m-1][j] == 'O'){
                board[m-1][j] = '1';
                dfs(board, m-1, j);
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == '1') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};

int main(){
    Solution sol;

    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};

    sol.solve(board);

    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[0].size(); j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}