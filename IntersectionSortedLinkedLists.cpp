/* The structure of the Linked list Node is as follows:

struct Node
{
	int data;
	Node *next;
	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

*/

class Solution {
	public:
	
    // TC:O(m + n), SC:O(1)
	Node* head = nullptr;
	Node* tail = nullptr;
	
	void push_back(int val) {
		// create a new Node here
		Node* newNode = new Node(val);
		// if linkedlist is empty,  point the head & tail to new Node
		if (head == nullptr) {
			head = tail = newNode;
			return;
		}
		
		tail->next = newNode;
		tail = newNode;
	}
	
	Node* findIntersection(Node* head1, Node* head2) {
		// code goes here.
		
		Node* list1 = head1;
		Node* list2 = head2;
		
		// keep traversing on both linked lists when list1 & list2 both point to a valid node
		while (list1 && list2) {
			
			if (list1->data < list2->data) {
				list1 = list1->next; // update the list1 to next node
			} else if (list1->data > list2->data) {
				list2 = list2->next; // update the list2 to next node
			} else {// when both list data matches means this is the intersected node
				// push a new intersected node into a new Linked list
				push_back(list1->data);
				// update both the list to next node
				list1 = list1->next;
				list2 = list2->next;
			}
		}
		return head; // return the intersected linked list head
	}
};
