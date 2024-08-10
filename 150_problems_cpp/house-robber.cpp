#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int prev = nums[0], cur = max(nums[0], nums[1]), temp;

        for(int i = 2; i<n; i++){
            if(cur >= nums[i]+prev){
                prev = cur;
                continue;
            }
        
            temp = cur;
            cur = nums[i]+prev;
            prev = temp;
        }
        return cur;
    }
};

int main(){
    Solution sol;

    vector<int> v = {4,1,1,3,1,1,4};

    cout << sol.rob(v);
}