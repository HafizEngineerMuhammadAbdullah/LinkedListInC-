/* Structure for Link list node
class Node {
	public:
	int data;
	Node* next;
	Node(int x) {
		data = x;
		next = nullptr;
	}
};
*/
class Solution {
	public:
	Node* deleteK(Node* head, int K) {
		// code here
		// create a dummy node
		Node* dummyNode = new Node(-1);
		
		// establish a connection between dummyNode & headNode
		dummyNode->next = head;
		
		Node* prev = dummyNode;
		Node* curr = head;
		
		int count = 1;
		
		while (curr) {
			// track every kth node of given LL using count
			// if count % k yields 0(completely divisible by k) that means that node is the kth node & should be deleted(remove/eliminate) from the list that node
			// if count is a multiple of k,means that means that is a kth node
			if (count % K == 0) {
				//   if kth node is found,delete it from list
				Node* nodeToDelete = curr;
				prev->next = curr->next;
				curr = curr->next;
				delete nodeToDelete;
			} else {
				// updata prev & curr pointers for the next iterations
				prev = curr;
				curr = curr->next;
			}
			count++;
		}
		
		
		Node* newHead = dummyNode->next;
		delete dummyNode;
		return newHead;//return the Head of LL
		
	}
};
