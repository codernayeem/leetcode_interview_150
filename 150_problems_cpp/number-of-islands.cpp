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

            if(nx < 0 || ny < 0 || nx == m || ny == n || grid[nx][ny] == '0') continue;

            grid[nx][ny] = '0';
            dfs(grid, nx, ny);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int c = 0;

        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1'){
                    c++;
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                }
            }
        }
        return c;
    }
};

int main(){
    Solution sol;

    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};

    cout << sol.numIslands(grid);
}