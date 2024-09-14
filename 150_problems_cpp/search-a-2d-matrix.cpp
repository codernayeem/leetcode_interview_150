#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        if(matrix[0][0] > target || matrix[n-1][m-1] < target) return false;

        int left = 0, right = n-1, mid;

        while(left<=right){
            mid = (left+right) >> 1;

            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        int x = left-1;

        left = 0, right = m-1;

        while(left<=right){
            mid = (left+right) >> 1;

            if(matrix[x][mid] == target)
                return true;
            else if(matrix[x][mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> v = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    cout << sol.searchMatrix(v, 3);
    return 0;
}