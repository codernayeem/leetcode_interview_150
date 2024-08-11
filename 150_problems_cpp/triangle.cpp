#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        if(n==1) return triangle[0][0];

        for(int i = 1; i<n; i++){
            for(int j = 0; j<=i; j++){
                if(j == 0){
                    triangle[i][j] += triangle[i-1][j];
                }else if(j == i){
                    triangle[i][j] += triangle[i-1][j-1];
                }else{
                    triangle[i][j] = min(triangle[i][j]+triangle[i-1][j-1], triangle[i][j]+triangle[i-1][j]);
                }
            }
        }

        int r = INT_MAX;
        for(int i = 0; i<n; i++){
            if(r > triangle[n-1][i]) r = triangle[n-1][i];
        }

        return r;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> v = {{2},{3,4},{6,5,7},{4,1,8,3}};

    cout << sol.minimumTotal(v);
}