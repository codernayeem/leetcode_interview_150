#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(auto i: tokens){
            if(i == "+" || i == "-" || i == "*" || i == "/"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                
                switch (i[0])
                {
                case '+':
                    y = y + x;
                    break;
                case '*':
                    y = y * x;
                    break;
                case '/':
                    y = y / x;
                    break;
                default:
                    y = y - x;
                    break;
                }
                s.push(y);
            }else{
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};

int main(){
    Solution sol;

    vector<string> v = {"2","1","+","3","*"};

    cout << sol.evalRPN(v);
}