#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int n = nums.size(), d;

        for(int i = 0; i<n; i++){
            d = target - nums[i];
            if(map.count(d)){
                return {map[d], i};
            }
            map.insert({nums[i], i});
        }
        return {};
    }
};

int main(){
    Solution sol;

    vector<int> n = {2, 8, 7, 9};
    vector<int> r = sol.twoSum(n, 9);

    cout << r[0] << ' ' << r[1];
}