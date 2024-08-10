#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        char c = 0;

        while(true){
            if(n & 1) ans = ans | 1;
            n = n >> 1;
            c++;
            
            if(!n) break;

            ans = ans << 1;
        }
        return ans << (32-c);
    }
};