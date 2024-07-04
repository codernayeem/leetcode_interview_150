#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    bool canConstruct(string ransomNote, string magazine) {
        int m[26] = {};

        for(auto ch: magazine){
            m[ch-'a']++;
        }
        for(auto ch: ransomNote){
            ch -= 'a';
            if(m[ch] == 0) return false;
            m[ch]--;
        }
        return true;
    }
};

int main(){
    Solution sol;

    cout << sol.canConstruct("aa", "aab");
}