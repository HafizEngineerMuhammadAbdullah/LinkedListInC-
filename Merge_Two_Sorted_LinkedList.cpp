#include <iostream>
using namespace std;
// creating a node class for Linked List
class Node {
public:
  int data;
  Node *next;

  // creating a parameterized constructor for node class
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

// creating a Linked List class
class LinkedList {
  Node *head;
  Node *tail;

  Node *mergeSortedLists(Node *h1, Node *h2) { // TC:O(m + n)
    // check if head1 is pointing to the NULL value means the remaining
    // data(head of the list2) in the list 2 should be return otherwise head1
    // would be return
    if (h1 == NULL || h2 == NULL) {
      return h1 == NULL ? h2 : h1;
    }

    // call the method itself to merge List for the remaining list node
    if (h1->data <= h2->data) {
      h1->next = mergeSortedLists(h1->next, h2);
      return h1;
    }
    // call the method itself to merge List for the remaining list node.
    else {
      h2->next = mergeSortedLists(h1, h2->next);
      return h2;
    }
  }

public:
  // creating a non-parameterized constructor for Linked List class
  LinkedList() { head = tail = NULL; }
  // creating a non-parameterized destructor for Linked List class
  ~LinkedList() {
    while (head != NULL) {
      pop_front();
    }
  }

  // method that push(add/insert) the element(data/newNode) at the front of
  // LinkedList
  void push_front(int val) { // TC:O(1)
    // create a new Node firstly
    Node *newNode = new Node(val);
    // if the head points towards the NULL value means still there is no node
    // available in the LinkedList(LinkedList is empty)
    if (head == NULL || tail == NULL) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }
  }

  // method that push(add/insert) the element(data/newNode) at the
  // tail(last/end) of LinkedList
  void push_back(int val) { // TC:O(1)
    // create a new Node firstly
    Node *newNode = new Node(val);
    // if the head points towards the NULL value means still there is no node
    // available in the LinkedList(LinkedList is empty)
    if (head == NULL || tail == NULL) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // method that pop(delete/remove) the element(data/node) at the front of
  // Linked List
  void pop_front() { // TC:O(1)
    // if the head points towards the NULL value means still there is no node
    // available in the LinkedList(LinkedList is empty)
    if (head == NULL || tail == NULL) {
      cout << "LinkedList is empty.Nothing to pop from front!" << endl;
      return;
    }
    // else if Linked List has at least one node available means LinkedList is
    // not empty.
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
  }

  // method that pop(delete/remove) the element(data/node) at the
  // tail(end/last/back) of Linked List
  void pop_back() { // TC:O(n)
    // if the head points towards the NULL value means still there is no node
    // available in the LinkedList(LinkedList is empty)
    if (head == NULL || tail == NULL) {
      cout << "LinkedList is empty.Nothing to pop from back!" << endl;
      return;
    }

    if (head == tail) { // only one/single node
      delete head;
      head = tail = NULL;
      return;
    }
    // else if Linked List has at least one node available means LinkedList is
    // not empty.
    Node *temp = head;
    while (temp->next != tail) {
      temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
  }

  // Merge Sorted Lists helper
  void mergeWith(LinkedList &other) {
    head = mergeSortedLists(this->head, other.head);
    return;
  }

  // method that traverse on the Linked List and print all of it's
  // elements(data)
  void printll() { // TC:O(n)
    // if the head points towards the NULL value means still there is no node
    // available in the LinkedList(LinkedList is empty)
    if (head == NULL || tail == NULL) {
      cout << "LinkedList is empty.Nothing to print!" << endl;
      return;
    }

    Node *temp = head;
    while (temp != NULL) {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};
int main() {
  LinkedList ll;
  ll.push_front(5);
  ll.push_front(4);
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);

  cout << "List ll: ";
  ll.printll();

  LinkedList lll;
  lll.push_back(1);
  lll.push_back(2);
  lll.push_back(3);
  lll.push_back(4);
  lll.push_back(5);

  cout << "List lll: ";
  lll.printll();

  // Merge lll into ll
  ll.mergeWith(lll);

  cout << "Merged List: ";
  ll.printll();

  return 0;
}
