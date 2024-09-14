#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";

        int n = a.size(), m = b.size();

        if(m > n){
            swap(a, b);
            swap(m, n);
        }

        bool carry = false;

        for(int i = 1; i<=m; i++){
            if(a[n-i] == '1' && b[m-i] == '1'){
                if(carry){
                    ans += '1';
                }else{
                    ans += '0';
                    carry = true;
                }
            }else if(a[n-i] == '0' && b[m-i] == '0'){
                if(carry){
                    ans += '1';
                    carry = false;
                }else{
                    ans += '0';
                }
            }else{
                if(carry){
                    ans += '0';
                }else{
                    ans += '1';
                }
            }
        }
        for(int i = 1; i<=n-m; i++){
            if(carry){
                if(a[n-m-i] == '1'){
                    ans += '0';
                }else{
                    carry = false;
                    ans += '1';
                }
            }else{
                ans += a[n-m-i];
            }
        }

        if(carry){
            ans += '1';
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution sol;

    cout << sol.addBinary("11", "1");
}