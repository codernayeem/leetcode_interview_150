#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;

        while(left<=right){
            mid = (left+right) >> 1;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return left;
    }
};

int main(){
    Solution sol;

    vector<int> v = {1, 2, 4, 6, 9};

    cout << sol.searchInsert(v, 3);
}