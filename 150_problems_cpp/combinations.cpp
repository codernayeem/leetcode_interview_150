#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N;

    void comb(vector<vector<int>>& ans, vector<int>& pre, int k, int start){
        if(k == 0) {
            ans.push_back(pre);
            return;
        }
        k--;
        for(int i = start; i<=N; i++){
            pre.push_back(i);
            comb(ans, pre, k, i+1);
            pre.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> pre;
        N = n;

        comb(ans, pre, k, 1);
        return ans;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> v =  sol.combine(4, 2);

    for(auto i: v){
        for(auto j: i)
            cout << j << " ";
        cout << endl;
    }
}