#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        if (m==0){
            nums1 = nums2;
            return;
        }


        int i=m-1, j=n-1, k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] <= nums2[j]){
                nums1[k] = nums2[j];
                j--; 
            }else{
                nums1[k] = nums1[i];
                i--; 
            }
            k--;
        }
        while(j>=0){
            nums1[k] = nums2[j];
            j--; 
            k--;
        }
        
    }
};

int main(){
    Solution sol;

    vector<int> v1 = {1,2,3,0,0,0};
    vector<int> v2 = {2,5,6};

    sol.merge(v1, 3, v2, 3);

    for(int j = 0; j<v1.size(); j++){
        cout << v1[j] << " ";
    }
}