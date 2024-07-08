#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    long calc(int n){
        long r = 0;
        while(n){
            r += (n % 10) * (n % 10);
            n /= 10;
        }
        return r;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        
        while(true){
            slow = calc(slow);
            fast = calc(fast);
            if(fast==1) return true;
            fast = calc(fast);
            if(fast==1) return true;
            if(fast == slow) return false;
        }
        return true;
    }
};

int main(){
    Solution sol;

    cout << sol.isHappy(19);
}