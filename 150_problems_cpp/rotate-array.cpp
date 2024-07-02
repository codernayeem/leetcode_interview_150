#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(!k) return;
        int n = nums.size();

        int i = 0, j = n-k-1;
        while(i<j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        i = n-k, j = n-1;
        while(i<j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        
        i = 0, j = n-1;
        while(i<j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

    }
};


int main(){
    Solution sol;

    vector<int> v1 = {1,2,3,5,0,6,7};

    sol.rotate(v1, 3);

    for(int j = 0; j<v1.size(); j++){
        cout << v1[j] << " ";
    }
}