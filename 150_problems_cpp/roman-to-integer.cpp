#include <bits/stdc++.h>
using namespace std;

int getSValue(char c){
    switch (c){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return 0;
}

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    int romanToInt(string s) {
        int m = 0, ans=0, t;

        for(int i = s.size(); i!=-1; i--){
            t = getSValue(s[i]);

            if(t < m){
                ans -= t;
                continue;
            }
            ans += t;
            m = t;
        }
        return ans;
    }
};


int main(){
    Solution sol;

    cout << sol.romanToInt("LVIII");
}