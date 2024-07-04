#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();

        int ans = n+1, sum = 0;

        while(r < n){
            sum = sum + nums[r];

            while(sum >= target){
                ans = min(ans, r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans == n+1 ? 0 : ans;
    }
};

int main(){
    Solution sol;
    
    vector<int> v1 = {2,3,1,2,4,3};

    cout << sol.minSubArrayLen(7, v1);
}