#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    bool hasCycle(ListNode *head) {
        ListNode *hare=head;

        if(!head) return false;

        while(hare->next && hare->next->next){
            head = head->next;
            hare = hare->next->next;
            if(head == hare) return true;
        }
        return false;
    }
};


int main(){
    Solution sol;

}