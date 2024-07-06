#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() / 2 > k)
            return largest(nums, k);
        
        
        return smallest(nums, nums.size()-k+1);
    }

    int largest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int> > pq;

        int i;

        for(i = 0; i < k; i++)
            pq.push(nums[i]);
        
        for(i = k; i < nums.size(); i++){
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }

    int smallest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        int i;

        for(i = 0; i < k; i++)
            pq.push(nums[i]);
        
        for(i = k; i < nums.size(); i++){
            if(pq.top() > nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};


int main(){
    Solution sol;

    vector<int> v = {3,2,1,5,6,4};
    vector<int> v1 = {1,2,3,4,5,6};

    int k = 5;

    cout << sol.findKthLargest(v, k) << endl;
    cout << sol.findKthLargest(v1, k) << endl;

    sort(v.begin(), v.end());

    cout << v[v.size() - k];
}