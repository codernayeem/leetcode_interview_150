#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    int removeElement(vector<int>& nums, int val) {
        int i, n = nums.size(), k;
        for(i = 0; i<n; i++){
            if(nums[i] == val) break;
        }
        if(i == n) return n;

        k = n-1;

        for(int j = i+1; j<n; j++){
            if(nums[j] == val){
                k--;
                continue;
            };
            nums[i] = nums[j];
            i++;
        }

        return k;
    }
};

int main(){
    Solution sol;
    
    vector<int> v1 = {0,1,2,2,3,0,4,2};

    int ans = sol.removeElement(v1, 2);

    cout << ans << endl;
    for(int i = 0; i<ans; i++){
        cout << v1[i] << " ";
    }
}