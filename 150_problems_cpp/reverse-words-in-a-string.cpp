#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void rev(string &s, int i, int j){
        while(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    string reverseWords(string s) {
        rev(s, 0, s.size()-1);
        int n = s.size();

        int k = 0, i = 0;

        while(i<n){
            if(s[i] == ' '){
                i++;
                continue;
            }

            k = i;
            while(s[i] != ' ' && i<n){
                i++;
            }
            rev(s, k, i-1);
        }

        i = 0, k = 0;

        while(i < n && s[i] == ' ') i++;
        
        while(i < n){
            if(s[i] == ' ' && s[k-1] == ' '){
                i++;
                continue;
            }
            s[k] = s[i];
            k++;
            i++;
        }

        if(n > 0 && s[n-1] == ' ') s.pop_back();
        while(k != n){
            s.pop_back();
            k++;
        }

        return s;
    }
};

int main(){
    Solution sol;

    cout << sol.reverseWords("  Hello World   ");
}