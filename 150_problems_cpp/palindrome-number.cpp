#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    bool isPalindrome(int x) {
        if(x < 0) return false;

        long y = 0, tx = x;

        while(x){
            y = y * 10 + x % 10;
            x /= 10;
        }
        return tx == y;
    }
};

int main(){
    Solution sol;

    cout << sol.isPalindrome(12121);
}