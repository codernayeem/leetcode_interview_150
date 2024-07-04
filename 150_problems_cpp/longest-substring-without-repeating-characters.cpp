#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    int lengthOfLongestSubstring(string s) {
        char m[128] = {};

        int l = 0, r = 0, n = s.size(), ans = 0;

        for( ; r < n; r++){
            m[s[r]]++;
            
            while(m[s[r]] == 2){
                m[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};

int main(){
    Solution sol;

    // cout << sol.lengthOfLongestSubstring("abcabcbb");
    cout << sol.lengthOfLongestSubstring("pwwkew");
    // cout << sol.lengthOfLongestSubstring("bbbbbb");
}