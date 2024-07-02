#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    bool isValid(string s) {
        stack<char> st;
        char c;
        int n = s.size();

        for(int i = 0; i<n;i++){
            if(s[i] == '[' || s[i] == '{' || s[i] == '(')
                st.push(s[i]);
            else if(st.empty())
                return false;
            else{
                c = s[i] - st.top();
                if(c != 1 && c != 2) return false;
                st.pop();
            }

        }
        if(st.empty()) return true;
        return false;
    }
};

int main(){
    Solution sol;

    cout << sol.isValid("(){}[]");
}