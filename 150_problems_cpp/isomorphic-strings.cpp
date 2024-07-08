#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();

        map<char, char> m;
        map<char, char> m2;

        for(int i = 0; i<n; i++){
            if(m[s[i]] == 0 && m2[t[i]] == 0){
                m[s[i]] = t[i];
                m2[t[i]] = s[i];
            }else if(m[s[i]] != t[i] && m2[t[i]] != s[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;

    cout << sol.isIsomorphic("paper", "title");
}