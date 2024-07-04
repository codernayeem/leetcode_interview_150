#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;

        while(i < j){
            if(nums[i] + nums[j] == target) return {i+1, j+1};
            
            if(nums[i] + nums[j] < target) i++;
            else j--;
        }

        return {};
    }
};

int main(){
    Solution sol;

    vector<int> n = {2, 7, 8, 9};
    vector<int> r = sol.twoSum(n, 9);

    cout << r[0] << ' ' << r[1];
}