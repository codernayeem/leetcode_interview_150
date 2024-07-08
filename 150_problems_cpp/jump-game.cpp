#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int n = nums.size();

        int maxIdx = 0;

        for(int i = 0; i<=maxIdx && i<n; i++){
            maxIdx = max(maxIdx, i + nums[i]);
        }
        return maxIdx >= n-1;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {2,3,1,1,4};

    cout << sol.canJump(nums);
}