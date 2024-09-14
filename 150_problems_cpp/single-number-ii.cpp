#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitCount[32] = {};
        int k;

        for(int& i: nums){
            k = 32;
            while(--k){
                if(i & (1 << k)){
                    bitCount[k]++;
                }
            }
            if(i & 1){
                bitCount[0]++;
            }
        }

        int ans = 0;

        for(int i = 0; i<32; i++){
            if(bitCount[i] % 3){
                ans = ans | (1 << i);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;

    vector<int> v = {2, 2, 2, 9};

    cout << sol.singleNumber(v);
}