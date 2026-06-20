/* Structure of a Node in linked list
class Node {
	public:
	int data;
	Node* next;
	
	Node(int x) {
		data = x;
		next = nullptr;
	}
}; */
class Solution {
	public:
	// TC:O(min(m,n)) where m & n are the size of the two LL
	// SC:O(1)
	bool areIdentical(Node *head1, Node *head2) {
		// code here
		// take two pointers that traverse each linkedlist and check if both linkedlists are same or not
		Node* temp1 = head1;
		Node* temp2 = head2;
		// loop through (scan) ll until one the pointer reach at the end of ll(means NULL)
		while (temp1 && temp2) {
		    // check if the node value is not same
			if (temp1->data != temp2->data) {
				return false;
			}
			
			// update the two pointers to check if next node of both LL is same or not
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		
		return temp1 == temp2;
	}
};
