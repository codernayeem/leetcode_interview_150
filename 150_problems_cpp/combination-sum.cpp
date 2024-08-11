#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void comb(vector<vector<int>>& ans, vector<int>& pre, vector<int>& candidates, int target, int start){
        if(start >= candidates.size() || target < 0) return;
        if(target == 0) {
            ans.push_back(pre);
            return;
        }

        pre.push_back(candidates[start]);
        comb(ans, pre, candidates, target-candidates[start], start);
        pre.pop_back();

        for(int i = start+1; i<candidates.size(); i++){
            pre.push_back(candidates[i]);
            comb(ans, pre, candidates, target-candidates[i], i);
            pre.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> pre;

        comb(ans, pre, candidates, target, 0);
        return ans;
    }
};

int main(){
    Solution sol;

    vector<int> v1 = {2, 3, 5};

    vector<vector<int>> v =  sol.combinationSum(v1, 5);

    for(auto i: v){
        for(auto j: i)
            cout << j << " ";
        cout << endl;
    }
}