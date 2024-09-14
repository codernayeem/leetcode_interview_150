#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n < 2) return n;

        int ans = 0;
        vector<int> candy(n, 1);

        // for satisfy conditions form left
        for(int i = 1; i<n; i++){
            if(ratings[i-1] < ratings[i]){
                candy[i] = candy[i-1] + 1;
            }
        }

        // for satisfy conditions form left & right
        for(int i = n-2; i>=0; i--){
            if(ratings[i+1] < ratings[i]){
                candy[i] = max(candy[i], candy[i+1] + 1);
            }
            ans += candy[i];
        }
        ans += candy[n-1];

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> v = {1, 2, 5, 4, 5};

    cout << sol.candy(v);
    return 0;
}