#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size();

        int l = prices[0], x;

        for(int i = 1; i<n; i++){
            x = prices[i];
            if(l < x){
                ans = max(ans, x-l);
            }else{
                l = x;
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