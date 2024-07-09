#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 3) return 0;

        int total = 0;
        int leftMax = height.front();
        int rightMax = height.back();

        int i = 1, j = n-2;

        while(i<=j){
            
            if(leftMax <= rightMax){
                if(leftMax -  height[i] > 0)
                    total += leftMax -  height[i];
                leftMax = max(leftMax, height[i]);
                i++;
            }else{
                if(rightMax -  height[j] > 0)
                    total += rightMax -  height[j];
                rightMax = max(rightMax, height[j]);
                j--;
            }
        }
        return total;
    }

};

int main(){
    Solution sol;

    // vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v = {4,2,0,3,2,5};

    cout << sol.trap(v);
}