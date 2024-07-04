#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    int removeDuplicates(vector<int>& nums) {
        int i = 0, cur = 1, n = nums.size(), k, count = 0;

        k = n;

        for(; cur<n; cur++){
            if(nums[i] == nums[cur]){
                if(count != 0){
                    k--;
                    continue;
                }
                count++;
            }else{
                count = 0;
            }

            i++;
            if(i != cur)
                nums[i] = nums[cur];
        }

        return k;
    }
};

int main(){
    Solution sol;
    
    vector<int> v1 = {0,0,1,1,1,2,2,3,3,4};

    int ans = sol.removeDuplicates(v1);

    cout << ans << endl;
    for(int i = 0; i<ans; i++){
        cout << v1[i] << " ";
    }
}