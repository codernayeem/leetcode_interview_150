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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k) return NULL;

        ListNode* newHead = head, *end = head;

        int n = 1;
        while(end->next){
            end = end->next;
            n++;
        }
        
        k %= n;
        if(!k) return head;

        end->next = head;
        k = n-k-1;

        while(k--){
            newHead = newHead->next;
        }

        end = newHead;
        newHead = newHead->next;
        end->next = NULL;

        return newHead;
    }
};

int main(){
    Solution sol;

}