#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int nby2 = nums.size() / 2;

        for(auto i: nums){
            m[i]++;
        }

        for (const auto& pair : m) {
            if (pair.second > nby2) {
                return pair.first;
            }
        }
        return -1;
    }
};


int main(){
    Solution sol;

    vector<int> v1 = {3,2,3,3,1,3};

    cout << sol.majorityElement(v1);
}