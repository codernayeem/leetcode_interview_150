#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return false;

        unordered_map<int, int> m;
        
        for(int i = 0; i < n; i++){
            if(m.find(nums[i]) != m.end()){
                if(i - m[nums[i]] <= k) return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

int main(){
    Solution sol;

    // vector<int> v = {1,2,3,1,3,3};
    // vector<int> v = {1,2};
    vector<int> v = {1,2,3,1};

    cout << sol.containsNearbyDuplicate(v, 3);
}