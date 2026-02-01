#include <iostream>
using namespace std;
// Definition for singly-linked list.
class ListNode {
public:
  int data;
  ListNode *next;
  // declare a parameterized constructor for node class
  ListNode(int data) {
    this->data = data;
    next = NULL;
  }
};

/// create a linked list class
class LinkedList {
private:
  ListNode *head;
  ListNode *tail;

  void updateTail() {
    if (head == NULL) {
      tail = NULL;
      return;
    }
    ListNode *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    tail = temp;
  }

  // function to swap nodes in pairs
  // Recursive helper logic
  ListNode *swapNodesInPair(ListNode *head) { // TC:O(1),SC:O(n)
    if (head == NULL) {
      cout << "LinkedList is empty.Nothing to Swap!" << endl;
      return head;
    }
    if (head->next == NULL) {
      cout << "LinkedList has only one node.Can't be Swap!" << endl;
      return head;
    }
    ListNode *temp = head;
    int count = 0;
    // check if Pairs of nodes(2-nodes) exist in current group
    while (count < 2) {
      if (temp == NULL) {
        return head;
      }
      temp = temp->next;
      count++;
    }

    // recursively call for the rest of the Linked List
    ListNode *prevNode = swapNodesInPair(temp);

    // reverse the current group
    temp = head;
    count = 0;
    while (count < 2) {
      if (temp == NULL) {
        break;
      }
      ListNode *next = temp->next;
      temp->next = prevNode;

      prevNode = temp;
      temp = next;
      count++;
    }
    return prevNode;
  }

  // methods that swap nodes in pairs:
  ListNode *swapPair(ListNode *head) { // TC:O(n),SC:O(1)
    // check if the head or head->next pointing towards the null value then
    // there is no need to swap the nodes simply return the head node.
    if (head == NULL || head->next == NULL) {
      return head;
    }
    // initialize three pointers
    ListNode *first = head;
    ListNode *sec = head->next;
    ListNode *prev = NULL;

    while (first != NULL && sec != NULL) {
      // create a third pointer and initialize it with sec->next
      ListNode *third = sec->next;
      // perform operations to swap the pairs of nodes
      sec->next = first;
      first->next = third;
      if (prev != NULL) {
        prev->next = sec;
      }
      // if prev is pointing to the NULL value means this is the first iteration
      else {
        head = sec;
      }

      // update the pointers for the next iterations
      prev = first;
      first = third;
      if (third != NULL) {
        sec = third->next;
      } else {
        sec = NULL;
      }
    }
    return head;
  }

public:
  // create a non-parameterized constructor for linked list class
  LinkedList() { head = tail = NULL; }

  // function to add(insert/push) a new node at the front of linked list
  void push_front(int val) {
    ListNode *newNode = new ListNode(val); // create a new node
    // if linked list is empty means head is pointing to NULL value
    if (head == NULL || tail == NULL) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }
  }
  // function to add(insert/push) a newNode at the end of LinkedList
  void push_back(int val) {
    // create a new node
    ListNode *newNode = new ListNode(val);
    // if linked list is empty means head is pointing to NULL value
    if (head == NULL || tail == NULL) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }
  // swap helper
  void swapHelper() {
    head = swapNodesInPair(head);
    updateTail();
    return;
  }

  // swap nodes in pairs helper
  void swapPair() {
    head = swapPair(head);
    updateTail();
    return;
  }

  // function to traverse the linked list and  print all of it's elements(data)
  // of linked list
  void printList() {
    // if head or tail is pointing to NULL value means there is no node
    // present(exist) in LinkedList
    if (head == NULL || tail == NULL) {
      cout << "LinkedList is empty.Nothing to print !" << endl;
      return;
    }

    ListNode *temp = head;

    while (temp != NULL) {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main() {
  LinkedList ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  ll.push_back(4);
  ll.push_back(5);
  // ll.push_back(6);

  ll.printList(); // before swapping nodes in pairs
  cout << "Before swap:\n";
  ll.printList();

  ll.swapHelper();

  cout << "After swap:\n";
  ll.printList();

  // cout << "Before swap:\n";
  // ll.printList();

  // ll.swapPair();

  // cout << "After swap:\n";
  // ll.printList();
  return 0;
}