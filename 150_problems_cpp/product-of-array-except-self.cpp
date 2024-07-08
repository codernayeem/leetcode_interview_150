#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 2){
            swap(nums[0], nums[1]);
            return nums;
        }

        vector<int> res(n, 1);

        for(int i = 1; i<n; i++){
            res[i] = res[i-1] * nums[i-1];
        }
        int cur = 1;
        for(int i = n-2; i>=0; i--){
            cur = cur * nums[i+1];
            res[i] *= cur;
        }
        return res;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1,2,3,4};

    nums = sol.productExceptSelf(nums);
}