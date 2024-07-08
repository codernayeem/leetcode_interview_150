#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int n = prices.size();

        int ans = 0;

        for(int i = 1; i<n ; i++){
            if(prices[i] > prices[i-1]){
                ans += prices[i] - prices[i-1];
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;

    vector<int> prices = {7,1,5,3,6,4};

    cout << sol.maxProfit(prices);
}