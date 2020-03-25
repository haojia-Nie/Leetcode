


// Analysis of the question
/*  
 1. ListNode always keep track of the pre/cur/next
 2. ListNode->next != NULL, SegFault issue
 3. carry value + value of curr node
 */


// Linked List
/* A Linked List is a linear data structure, 
one complete def of Node consists a pointer to the next Node in the list 
*/

//Type:
//Singly Linked List 

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
}

//Doubley Linked List

struct ListNode {
	int val;
	ListNode *prev;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
}



