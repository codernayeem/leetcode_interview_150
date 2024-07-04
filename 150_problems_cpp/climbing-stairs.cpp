#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n < 4) return n;

        int prev = 1, curr = 2, temp;
        for (int i = 3; i <= n; i++) {
            temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};

int main(){
    Solution sol;

    cout << sol.climbStairs(40);

}