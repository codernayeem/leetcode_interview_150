#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    int n;

    pair<int, int> pos(int r, int c){
        return {c, n-1-r};
    }

    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();
        pair<int, int> coor;

        for(int i = 0; i<n/2; i++){
            for(int j = i; j<n-i-1; j++){
                coor = pos(i, j);
                swap(matrix[i][j], matrix[coor.first][coor.second]);

                coor = pos(coor.first, coor.second);
                swap(matrix[i][j], matrix[coor.first][coor.second]);

                coor = pos(coor.first, coor.second);
                swap(matrix[i][j], matrix[coor.first][coor.second]);
            }
        }
    }

    
    // void rotate(vector<vector<int>>& matrix) {
    //     reverse(matrix.begin(), matrix.end());
    //     for (int i = 0; i < matrix.size(); ++i) {
    //         for (int j = i + 1; j < matrix[i].size(); ++j)
    //             swap(matrix[i][j], matrix[j][i]);
    //     }
    // }
};


int main(){
    Solution sol;

    vector<vector<int> > v = {{1,2,3},{4,5,6},{7,8,9}};

    sol.rotate(v);

    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[i].size(); j++){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}