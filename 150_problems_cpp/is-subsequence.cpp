#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.length(), m = s.length(), i, j;

        if(n<m) return false;

        for(i = 0, j = 0; i<n && j<m; i++){
            if(s[j] == t[i]) j++;
        }

        return j == m;
    }
};

int main(){
    Solution sol;

    cout << sol.isSubsequence("aab", "acab");
}