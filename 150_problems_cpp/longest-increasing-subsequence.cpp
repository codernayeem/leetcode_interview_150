#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;

        vector<int> dp(n, 1);

        int r = 1;

        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[j] < nums[i] && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
            r = max(r, dp[i]);
        }

        return r;
    }
};


int main(){
    Solution sol;

    vector<int> v = {10,9,2,5,3,7,101,18};

    cout << sol.lengthOfLIS(v);
}