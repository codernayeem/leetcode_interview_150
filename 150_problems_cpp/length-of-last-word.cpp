#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    int lengthOfLastWord(string s) {
        int ans = 0;
        int i = s.size() - 1;

        for(; i>=0; i--){
            if(s[i] != ' ')
                break;
        }

        for(; i>=0; i--){
            if(s[i] == ' ')
                break;
            
            ans++;
        }

        return ans;
    }
};


int main(){
    Solution sol;

    cout << sol.lengthOfLastWord("   fly me   to   the moon  ");
}