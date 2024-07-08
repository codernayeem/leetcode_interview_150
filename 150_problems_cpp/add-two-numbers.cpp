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
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *ans = l1;
        bool carry = 0;

        ListNode *prev1 = NULL, *prev2 = NULL;

        while(l1 && l2){
            l1->val += l2->val + carry;

            if(l1->val > 9){
                l1->val -= 10;
                carry = 1;
            }else{
                carry = 0;
            }
            prev1 = l1;
            prev2 = l2;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l2){
            prev1->next = l2;
            l1 = l2;
        }

        if(!carry) return ans;

        while(l1){
            l1->val += carry;

            if(l1->val < 10){
                return ans;
            }
        
            l1->val -= 10;

            prev1 = l1;
            l1 = l1->next;
        }

        prev1->next = new ListNode(1);

        return ans;
    }
};


int main(){
    Solution sol;

    ListNode *a = new ListNode(9);
    a = new ListNode(9, a);
    a = new ListNode(9, a);
    a = new ListNode(9, a);

    ListNode *b = new ListNode(9);
    b = new ListNode(9, b);
    b = new ListNode(9, b);
    b = new ListNode(9, b);
    b = new ListNode(9, b);
    b = new ListNode(9, b);
    b = new ListNode(9, b);

    ListNode *c = sol.addTwoNumbers(a, b);

    while(c){
        cout << c->val;
        c = c->next;
    }


}