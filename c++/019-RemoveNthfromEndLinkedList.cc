#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *cur = newHead;
        ListNode *prev = newHead;
        
        
        if (!head->next){
            return nullptr;
        }
        // set the distance 
        while (n > 0){
            cur = cur->next;
            n--;
        }
        
        // do the following 
        while (cur->next != nullptr){
            prev = prev->next;
            cur = cur->next;
        }
        
        prev->next = prev->next->next;
              
        return newHead->next;
    }
};
