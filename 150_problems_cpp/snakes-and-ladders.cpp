#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    int to1D(int x, int y, int n) {
        return x * n + y;
    }

    pair<int, int> to2D(int index, int n) {
        int x = index / n;
        int y = index % n;
        return {x, y};
    }

    int bfs(vector<vector<int> >& grid, int V){
        vector<vector<bool> > vis(V, vector<bool>(V, false));
        vector<vector<int> > dis(V, vector<int>(V, INT_MAX));

        vis[0][0] = true;
        dis[0][0] = 0;

        queue<pair<int, int>> q;
        q.push({0, 0});

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 1; i<=6; i++){
                auto [nx, ny] = to2D(to1D(x, y, V) + i, V);
                if(nx >= V || ny >= V) continue;

                if(grid[nx][ny] != -1){
                    auto p = to2D(grid[nx][ny]-1, V);
                    nx = p.first;
                    ny = p.second;
                }
                
                if(vis[nx][ny]) continue;

                vis[nx][ny] = true;
                dis[nx][ny] = dis[x][y] + 1;

                if(nx == V-1 && ny == V-1) return dis[V-1][V-1];

                q.push({nx, ny});
            }
        }


        return dis[V-1][V-1] == INT_MAX ? -1 : dis[V-1][V-1];
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<vector<int>> grid;
        int n = board.size();
        
        for(int i = n-1; i!=-1; i--){
        
            if((n-i) % 2 == 0){
                reverse(board[i].begin(), board[i].end());
            }

            grid.push_back(board[i]);
        }

        return bfs(grid, n);
    }
};

int main(){
    Solution sol;

    // vector<vector<int>> board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    // vector<vector<int>> board = {{-1,-1,2,21,-1},{16,-1,24,-1,4},{2,3,-1,-1,-1},{-1,11,23,18,-1},{-1,-1,-1,23,-1}};
    // vector<vector<int>> board = {{-1,7,-1},{-1,6,9},{-1,-1,2}};
    vector<vector<int>> board = {{-1,-1,-1,46,47,-1,-1,-1},{51,-1,-1,63,-1,31,21,-1},{-1,-1,26,-1,-1,38,-1,-1},{-1,-1,11,-1,14,23,56,57},{11,-1,-1,-1,49,36,-1,48},{-1,-1,-1,33,56,-1,57,21},{-1,-1,-1,-1,-1,-1,2,-1},{-1,-1,-1,8,3,-1,6,56}};


    cout << sol.snakesAndLadders(board);
}