#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;

        int ans = 0;

        while(i < j){
            ans = max(ans, (j-i) * min(height[i], height[j]));

            if(height[i] < height[j]) i++;
            else j--;
        }

        return ans;
    }
};

int main(){
    Solution sol;

    vector<int> v = {1,8,6,2,5,4,8,3,7};

    cout << sol.maxArea(v);
}