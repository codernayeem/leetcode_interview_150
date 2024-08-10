#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head;
        int len = 1;

        while(slow->next != NULL){
            slow = slow->next;
            len++;
        }

        n = len - n;

        if(n == 0)
            return head->next;
        
        slow = head;
        while(n != 1){
            slow = slow->next;
            n--;
        }
        slow->next = slow->next->next;

        return head;
    }
};

int main(){
    Solution sol;

}