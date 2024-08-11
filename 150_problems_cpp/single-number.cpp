#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r = 0;
        for(auto i: nums) r ^= i;
        return r;
    }
};

int main(){
    Solution sol;

    vector<int> v = {4,1,2,1,2};

    cout << sol.singleNumber(v);
}