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
      // exist (present) in our Doubly Linked  list
      else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
      }
    }

    // add(push/insert) the newNode at the end(back) of the Doubly linked list:
    void push_back(int val) {
      Node *newNode = new Node(val); // creating a newNode
      // if our Doubly linked list is empty means our head is pointing to the NULL
      // value
      if (head == NULL) {
        head = tail = newNode;
      }
      // if our Doubly linked list is not empty means there is at least one node
      // exist (present) in our Doubly linked list
      else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
      }
    }

    // delete(remove/pop) the node from the front of the Doubly linked list:
    void pop_front() {
      // if our Doubly linked list is empty means our head is pointing to the NULL
      // value
      if (head == NULL) {
        cout << "Doubly Linked List is empty.Nothing to pop!" << endl;
        return;
      }

      Node *temp = head;
      head = head->next;
      // if the only one node is present in the doubly linked list
      if (head == NULL) {
        tail = NULL;
      }
      // if more than one node is present in the doubly linked list
      else if (head != NULL) {
        head->prev = NULL;
      }
      temp->next = NULL;
      delete temp; // to delete the first node from the doubly linked list
    }

    // delete(remove/pop) the node from the end(back) of the Doubly linked list:
    void pop_back() {
      // if our Doubly linked list is empty means our head is pointing to the NULL
      // value
      if (head == NULL) {
        cout << "Doubly Linked List is empty.Nothing to pop!" << endl;
        return;
      }
      Node *temp = tail;
      tail = tail->prev;
      // if the only one node is present in the doubly linked list
      if (tail == NULL) {
        head = NULL;
      }
      // if more than one node is present in the doubly linked list
      else if (tail != NULL) {
        tail->next = NULL;
      }
      temp->prev = NULL;
      delete temp; // to delete the last node from the doubly linked list
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
    // dll.printDll();
    dll.push_back(3);
    dll.push_back(2);
    dll.push_back(1);

    dll.printDll();

    dll.pop_back();
    dll.pop_back();

    dll.printDll();

    return 0;
  }