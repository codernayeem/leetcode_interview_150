#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sum(m, vector<int>(n, INT_MAX));

        sum[0][0] = grid[0][0];

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i+1 != m && sum[i+1][j] > sum[i][j] + grid[i+1][j]){
                    sum[i+1][j] = sum[i][j] + grid[i+1][j];
                }
                if(j+1 != n && sum[i][j+1] > sum[i][j] + grid[i][j+1]){
                    sum[i][j+1] = sum[i][j] + grid[i][j+1];
                }
            }
        }
        return sum[m-1][n-1];
    }
};

int main(){
    Solution sol;

    vector<vector<int>> v = {{1,3,1},{1,5,1},{4,2,1}};

    cout << sol.minPathSum(v);
}