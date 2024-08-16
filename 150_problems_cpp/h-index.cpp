#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int i;
        for(i = 0; i<citations.size(); i++){
            if(citations[i] < i+1)
                return i;
        }
        return i;
    }
};

int main(){
    Solution sol;

    vector<int> v = {1, 2, 6, 4, 5};

    cout << sol.hIndex(v);
}