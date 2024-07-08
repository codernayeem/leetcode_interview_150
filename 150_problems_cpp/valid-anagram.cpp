#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(n != t.size()) return false;

        int m[26] = {};

        for(int i = 0; i<n; i++){
            m[s[i]-'a']++;
            m[t[i]-'a']--;
        }

        for(int val : m){
            if(val) return false;
        }
        
        return true;
    }
};


int main(){
    Solution sol;

    cout << sol.isAnagram("abbac", "cbbaa");
}