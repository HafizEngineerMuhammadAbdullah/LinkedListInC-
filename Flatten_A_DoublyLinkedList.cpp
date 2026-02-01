#include <iostream>
using namespace std;

// creating a class for each Node of Doubly Linked List:
class Node {
public:
  int data;
  Node *next;
  Node *prev;

  // creating a parameterized constructor for each node of doubly linked list
  Node(int data) {
    this->data = data;
    next = prev = NULL;
  }
};

// creating a class of Doubly Linked List:
class DoublyLinkedList {
  Node *head;
  Node *tail;

public:
  // creating a non-parameterized constructor of doubly linked list.
  DoublyLinkedList() { head = tail = NULL; }

  // add(push/insert) the newNode at the front of the Doubly linked list:
  void push_front(int val) {
    Node *newNode = new Node(val); // creating a newNode
    // if our Doubly linked list is empty means our head is pointing to the NULL
    // value
    if (head == NULL) {
      head = tail = newNode;
    }
    // if our Doubly linked list is not empty means there is at least one node
    // exist (present) in our linked list
    else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  // Flatten A Multi-Level Doubly Linked List
  Node *flatten() {
    if (head == NULL) {
      cout << "Doubly Linked List is empty.Nothing to flatten!" << endl;
      return;
    }

    Node *curr = head;
    while (curr != NULL) {

      // flatten a doubly linked list
      // if the current child exist and point to valid node
      if (curr->child != NULL) {
        Node *next = curr->next;
        curr->next = flatten(curr->child);
        curr->next->prev = curr;
        curr->child = NULL;

        // find the tail node
        while (curr->next != NULL) {
          curr = curr->next;
        }

        // attach the tail with the next node
        if (next != NULL) {
          curr->next = next;
          next->prev = curr;
        }
      }
      curr = curr->next;
    }
    return head;
  }

  // print the Doubly linked list:
  void printDll() {
    // if our Doubly linked list is empty means our head is pointing to the NULL
    // value
    if (head == NULL) {
      cout << "Doubly Linked List is empty.Nothing to print!" << endl;
      return;
    }
    cout << "NULL<=>";
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->data << "<=>";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};
int main() {
  DoublyLinkedList dll;
  dll.push_front(43);
  dll.push_front(23);
  dll.push_front(13);
  dll.push_front(384);
  dll.printDll();
}