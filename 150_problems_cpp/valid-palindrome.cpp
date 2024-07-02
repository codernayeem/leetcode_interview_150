#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        int n = s.size();

        while(i<j){
            while(i<j && !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= '0' && s[i] <= '9')){
                i++;
            }
            
            while(i<j && !(s[j] >= 'A' && s[j] <= 'Z') && !(s[j] >= 'a' && s[j] <= 'z') && !(s[j] >= '0' && s[j] <= '9')){
                j--;
            }
            
            if(i>=j) return true;

            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + ('a' - 'A');
            }
            if (s[j] >= 'A' && s[j] <= 'Z') {
                s[j] = s[j] + ('a' - 'A');
            }

            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;

    }
};


int main(){
    Solution sol;

    cout << sol.isPalindrome("Hello, Hi");
}