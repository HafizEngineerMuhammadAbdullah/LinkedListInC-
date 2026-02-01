#include <iostream>
using namespace std;

// creating a Node class for Linked List:
class Node {
public:
  int data;
  Node *next;

  // creating a parameterized constructor for Node Class
  Node(int data) {
    this->data = data;
    next = NULL;
  }
};

// creating a structure of the Linked List class
class List {
  Node *head;
  Node *tail;

public:
  // creating a non-parameterized constructor for Linked-List class
  List() { head = tail = NULL; }

  // add(insert/push) the newNode  at the front of the LinkedList
  void push_front(int val) {

    // creating a newNode firstly
    Node *newNode = new Node(val);

    // if the Linked-List is alredy empty means head is pointing to the NULL
    // value
    if (head == NULL) {
      head = tail = newNode; // head points to the newNode
    } else {
      newNode->next = head;
      head = newNode;
    }
  }

  // add(insert/push) the newNode at the end of Linked List
  void push_back(int val) {
    // creating a newNode of the Linked List
    Node *newNode = new Node(val);
    // if the head is pointing to the NULL value means there is no element(node)
    // exist in the Linked List which means Linked List is empty.
    if (head == NULL || tail == NULL) {
      head = tail = newNode;
      return;
    }

    tail->next = newNode;
    tail = newNode;
  }

  // reverse node in K Group
  // Time: O(n)
  // Space: O(n/k) (due to recursion)
  Node *reverseNodesInKGroup(Node *head, int k) {
    // if head is pointing to the NULL value means Linked List is empty
    if (head == NULL) {
      return NULL;
    }

    Node *temp = head;
    int count = 0;
    // firsly check if the K-nodes exist in current group
    while (count < k) {
      if (temp == NULL) {
        return head;
      }
      temp = temp->next;
      count++;
    }
    // recursively call for the rest of the Linked List
    Node *prevNode = reverseNodesInKGroup(temp, k);
    // reverse the current group
    temp = head;
    count = 0;
    while (count < k) {
      if (temp == NULL) {
        break;
      }
      Node *next = temp->next;
      temp->next = prevNode;

      prevNode = temp;
      temp = next;
      count++;
    }
    return prevNode;
  }
  // calling the reverseKGroup function
  void reverseKGroup(int k) {
    head = reverseNodesInKGroup(head, k);
    return;
  }

  // treverse the whole LinkedList and print all of it's elements
  void printll() {
    if (head == NULL) {
      cout << "Singly Linked List is already empty.Nothing to print!" << endl;
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
  List ll;
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  ll.push_front(0);

  ll.printll(); // before reversing the K-group nodes

  ll.reverseKGroup(2);

  ll.printll(); // after reversing the K-group nodes
}