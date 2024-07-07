#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int c = 0;

        while(n){
            c+= n & 1;
            n = n >> 1;
        }
        return c;
    }
};


int main(){
    Solution sol;

    cout << sol.hammingWeight(12121);
}