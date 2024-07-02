#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        sort(strs.begin(), strs.end());
        string a = strs[0], b = strs[strs.size()-1];
        int minSize = a.length();
        if(minSize > b.length()) minSize = b.length();

        char c;
        for(int pos = 0; pos < minSize; pos++){
            if(a[pos] != b[pos]) return s;
            s += a[pos];
        }
        return s;
    }
};

int main(){
    Solution sol;

    vector<string> v = {"flower","flow","flight"};

    cout << sol.longestCommonPrefix(v);
}