#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = nums.size();

        for(int i = 0; i < n-2; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            int left = i+1, right = n-1, target = -nums[i];

            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == target){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }else if(sum > target){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;

    vector<int> v = {-1, -1, 1, 2, 3, 4, 5};

    sol.threeSum(v);
}