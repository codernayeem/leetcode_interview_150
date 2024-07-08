#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int start = 0;
        int sum = 0;

        for(int i = 0; i<n; i++){
            gas[i] -= cost[i];
            total += gas[i];
            sum += gas[i];

            if(sum < 0){
                sum = 0;
                start = i + 1;
            }
        }
        if(total < 0) return -1;
        return start;
    }
};

int main(){
    Solution sol;

    vector<int> v = {2,3,4};
    vector<int> v1 = {3,4,3};

    cout << sol.canCompleteCircuit(v, v1);
}