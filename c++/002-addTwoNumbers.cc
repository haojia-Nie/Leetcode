#include <iostream>

using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {} // constructor
};


class Solution{
    public:
        ListNode *addTwoNumber(ListNode *l1, ListNode *l2) {
            ListNode preHead(0);
            ListNode *p = &preHead;
            int extra = 0;
            while(l1 || l2 || extra) {
                int sum = (l1 ? l1->val: 0) + (l2 ? l2->val: 0) + extra;
                extra = sum / 10;
                p->next = new ListNode(sum % 10);
                p = p->next;
                l1 = l1 ? l1->next : l1;
                l2 = l2 ? l2->next : l2;

            }
            return preHead.next;
        }
};



//Helper function
//free_list: free heap-allocated memory when constructing LinkedList
//           and also print the value of the Node
void free_list(ListNode ** head) {
    ListNode * current = *head;
    ListNode * next;
    
    while(current) {
        cout << current->val;
        next = current->next;
        if(next) cout << " >> " ;
        free(current);
        current = next;
    }
    cout << endl;
}

int main() {
    Solution b;
    ListNode * head_1 = new ListNode(3);
    head_1->next = new ListNode(3);
    ListNode * head_2 = new ListNode(7);
    head_2->next = new ListNode(8); // 33 + 87 = 120
    
    ListNode * result = b.addTwoNumber(head_1, head_2);
    
    cout << "Node 1: " ;
    free_list(&head_1);
    cout << "Node 2: " ;
    free_list(&head_2);
    cout << "Result: " ;
    free_list(&result);

    /* Output
       Node 1: 3 >> 3
       Node 2: 7 >> 8
       Result: 0 >> 2 >> 1
    */
}
