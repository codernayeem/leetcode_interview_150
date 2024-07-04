#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    string minWindow(string s, string t) {
        int l = 0, r = 0, n = s.size();

        vector<int> m(128, 0);

        int neg_count = t.size();

        for(auto ch: t){
            m[ch]--;
        }

        int ansL = 1, ansR = INT_MAX;

        while(r < n){
            m[s[r]]++;

            if(m[s[r]] < 1) neg_count--;

            while(neg_count == 0){
                if(ansR-ansL > r-l){
                    ansL = l;
                    ansR = r;
                }
                m[s[l]]--;

                if(m[s[l]] < 0) neg_count++;

                l++;
            }
            r++;
        }
        if(ansR == INT_MAX) return "";

        string str = "";
        while(ansL <= ansR){
            str += s[ansL++];
        }
        return s.substr(ansL, ansR-ansL);
    }
};

int main(){
    Solution sol;

    cout << sol.minWindow("ADOBECODEBANC", "ABC");
}