#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long n2 = n;

        if(n2 < 0){
            x = 1 / x;
            n2 = -n2;
        }
        
        double ans = 1;
        int c = 0;

        while(n2){
            if(n2 & 1)
                ans *= x;
            x *= x;
            n2 >>= 1;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.myPow(-1.000000001, INT_MAX);
    return 0;
}