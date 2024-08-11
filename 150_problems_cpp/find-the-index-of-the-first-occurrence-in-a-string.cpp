#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // KMP ALGO
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();

        if(m > n) return -1;

        vector<int> lps(m);
        lps[0] = 0;

        int i=1;
        int pre = 0;
        
        while(i<m){
            while (pre > 0 and needle[i] != needle[pre])
                pre = lps[pre-1];
            
            if(needle[pre] == needle[i]){
                pre++;
                lps[i] = pre;
            }
            i++;
        }
        
        pre = 0;

        for(i = 0; i<n; i++){
            while (pre > 0 and haystack[i] != needle[pre])
                pre = lps[pre-1];

            if(haystack[i] == needle[pre]){
                pre++;
                if(pre == m) return i - pre + 1;
                continue;
            }
            
            pre = lps[pre];
        }
        return -1;
    }
};


int main(){
    Solution sol;

    cout << sol.strStr("sadbutsad", "sad") << endl;
    cout << sol.strStr("leetcode", "leeto") << endl;
    cout << sol.strStr("mississippi", "issip") << endl;
}