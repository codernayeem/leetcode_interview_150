#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string, char> m;

        bool arr[26]= {};

        istringstream iss(s);
        string word;
        int i = 0, n = pattern.size();

        while (iss >> word) {
            if(i == n) return false;
            if(m[word] == 0 && !arr[pattern[i]-'a']){
                m[word] = pattern[i];
                arr[pattern[i]-'a'] = true;
            }else if(m[word] != pattern[i]){
                return false;
            }
            i++;
        }
        return i == n;
    }
};

int main(){
    Solution sol;

    cout << sol.wordPattern("abbb", "dog cat cat fish");
}