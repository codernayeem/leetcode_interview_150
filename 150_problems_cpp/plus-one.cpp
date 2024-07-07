#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        digits[n-1]++;

        for(int i = n-2; i>=0; i--){
            if(digits[i+1] == 10){
                digits[i+1] = 0;
                digits[i]++;
            }
        }
        if(digits[0] == 10){
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main(){
    Solution sol;
    
    vector<int> v1 = {9,4,9};

    sol.plusOne(v1);

    for(int j = 0; j<v1.size(); j++){
        cout << v1[j] << " ";
    }
}