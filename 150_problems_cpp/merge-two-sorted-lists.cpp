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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* bac;
        if(list1->val <= list2->val){
            bac = list1;
            list1 = list1->next;
        }else{
            bac = list2;
            list2 = list2->next;
        }
        ListNode* temp = bac;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if(list1==nullptr)
            temp->next = list2;
        else
            temp->next = list1;
        return bac;
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

    ListNode *c = sol.mergeTwoLists(a, b);

    while(c){
        cout << c->val << " ";
        c = c->next;
    }


}