#include <bits/stdc++.h>
using namespace std;

string m[8] = {
    "abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"
};

class Solution {
public:
    void comb(string& pre, vector<string> &ans, string& digits){
        if(digits.empty()) {
            ans.push_back(pre);
            return;
        }

        char c = digits.back();
        digits.pop_back();

        for(auto i: m[c - '2']){
            pre.push_back(i);
            comb(pre, ans, digits);
            pre.pop_back();
        }
        digits.push_back(c);
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        reverse(digits.begin(), digits.end());

        vector<string> ans;
        string s;
        comb(s, ans, digits);
        return ans;
    }
};


int main(){
    Solution sol;

    vector<string> v =  sol.letterCombinations("23");

    for(auto i: v) cout << i << endl;
}