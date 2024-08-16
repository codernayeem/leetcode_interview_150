#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void comb(vector<string>& ans, string& pre, int op, int cl) {
        if(op > cl) return;

        if(op == 0 && cl == 0){
            ans.push_back(pre);
            return;
        }

        if(op > 0){
            pre.push_back('(');
            comb(ans, pre, op-1, cl);
            pre.pop_back();
        }
        if(cl > 0){
            pre.push_back(')');
            comb(ans, pre, op, cl-1);
            pre.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string pre = "(";

        comb(ans, pre, n-1, n);
        return ans;
    }
};


int main(){
    Solution sol;

    vector<string> v = sol.generateParenthesis(5);

    for(auto i: v) cout << i << endl;

}