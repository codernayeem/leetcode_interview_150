#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        int maxIdx = 0;

        for(int i = 0; i<n; i++){
            for(int j = maxIdx+1; j<=i+nums[i] && j<n; j++){
                dp[j] = dp[i]+1;
            }
            maxIdx = max(maxIdx, i+nums[i]);
            if(maxIdx >= n-1) return dp[n-1];
        }
        return dp[n-1];
    }
};

int main(){
    Solution sol;

    // vector<int> nums = {2,3,1,1,4};
    vector<int> nums = {2,0,2,0,1};

    cout << sol.jump(nums);
}