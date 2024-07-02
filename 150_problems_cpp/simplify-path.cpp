#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    string simplifyPath(string path) {
        stack<string> s;

        string cur;
        
        int j = 1, n = path.size();
        while(j < n){
            cur = "";
            while(j != n && path[j] != '/'){
                cur += path[j];
                j++;
            }
            if(cur == "" || cur == "."){
                j++;
                continue;
            }
            if(cur == ".."){
                if (!s.empty()) s.pop();
            }else{
                s.push(cur);
            }
            j++;
        } 

        if(s.empty()) return "/";

        string ans = "";
        while (!s.empty())
        {
            ans = "/" + s.top() + ans;
            s.pop();
        }
        return ans;
    }
};

int main(){
    Solution sol;

    cout << sol.simplifyPath("/home/user/Documents/../Pictures");
    // cout << sol.simplifyPath("/home/");
}