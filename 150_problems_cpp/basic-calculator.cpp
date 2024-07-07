#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    int calculate(string s) {
        signed char sign = 1; 
        int ans = 0, n = s.size(), i = 0;

        long x;
        char ch;

        stack<pair<int, signed char> > stk;

        for(i = 0; i<n; i++){
            ch = s[i];
            if(ch == ' ') continue;

            if(isdigit(ch)){
                x = ch - '0';

                for(i = i+1; i<n && isdigit(s[i]); i++){
                    x = x * 10 + (s[i] - '0');
                }
                i--;
                ans += sign*x;
            }else if(ch == '('){
                stk.push({ans, sign});
                ans = 0;
                sign = 1;
            }else if(ch == ')'){
                ans = stk.top().second * ans + stk.top().first;
                stk.pop();
                sign = 1;
            }else if(ch == '-'){
                sign = -1;;
            }else if(ch == '+'){
                sign = 1;;
            }
        }

        return ans;
    }
};


int main(){
    Solution sol;

    cout << sol.calculate(" 2-1 + 24 ") << endl;
    cout << sol.calculate("2147483647") << endl;
    cout << sol.calculate("(6)-(8)-(7)+(1+(6))") << endl;
    cout << sol.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << sol.calculate("5+(0-9)") << endl;
}