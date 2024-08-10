#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i<=amount; i++){
            for(auto x: coins){
                x = i - x;
                if(x < 0 || dp[x] == INT_MAX)
                    continue;
                
                if(dp[i] > dp[x] + 1) 
                    dp[i] = dp[x] + 1;
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};


int main(){
    Solution sol;

    vector<int> v = {1, 2, 3, 4, 5};

    cout << sol.coinChange(v, 36);
}