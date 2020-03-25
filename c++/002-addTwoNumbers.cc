
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
}

//----------------------------------------My Ugly-for-now solution

class Solution{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
		ListNode * ans = new ListNode(0);
		int carry = 0;
		ListNode * curr_node = ans;
		while(l1 != NULL && l2 != NULL){
			curr = (l1->val + l2->val + carry) % 10;
			carry = (l1->val + l2->val + carry) / 10;
			if (curr_node == NULL)
				curr_node = new ListNode(curr);
			else 
				curr_node->val = curr;	

			curr_node = curr_node->next;
		}
		if (l1 == NULL){
			l2->val = l2->val + carry;
			curr_node = l2;
		}
		else if (l2 == NULL){
			l1->val = l1->val + carry;
			curr_node = l1;
		}
		return ans;
	}
}


//---------------------------------------runtime no delay

class Solution{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
		ListNode preHead(0);
		ListNode *p = &preHead;
		int extra = 0;
		while (l1 || l2 || extra){
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
			extra = sum / 10;
			p->next = new ListNode(sum % 10);
			p = p->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return preHead.next
	}
}