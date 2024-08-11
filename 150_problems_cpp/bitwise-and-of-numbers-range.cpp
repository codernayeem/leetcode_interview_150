#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // removing uncommon bits from the right
        int c = 0;
        while(left != right){
            left &= 0xFFFFFFFE << c;
            right &= 0xFFFFFFFE << c;
            c++;
        }
        return left;
    }
};

int main(){
    Solution sol;

    cout << sol.rangeBitwiseAnd(5, 7);
}