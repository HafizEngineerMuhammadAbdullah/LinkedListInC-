#include <iostream>
using namespace std;

// create a class for LinkedList Node
struct ListNode {
  int data;
  ListNode *next;
  ListNode(int data) : data(data), next(nullptr) {}
};

// create a class for Linked List
class LinkedList {
private:
  ListNode *head;

  /*
  Time Complexity: O(n)
  Space Complexity: O(n) (due to recursion stack)
  */
  // helper function to reverse the Linked List using Recursion
  ListNode *reverse(ListNode *prev, ListNode *curr) {
    if (curr == nullptr)
      return prev;
    
    ListNode *next = curr->next;
    curr->next = prev;
    return reverse(curr, next);
  }

public:
  // constructor to initialize the head pointer of Linked List
  LinkedList() : head(nullptr) {}
  // destructor to free the memory allocated for Linked List
  ~LinkedList() {
    ListNode *temp = head;
    while (temp) {
      ListNode *next = temp->next;
      delete temp;
      temp = next;
    }
  }
  // push(add) the elements to the front of Linked List
  void push_front(int val) {
    ListNode *newNode = new ListNode(val);
    if (head == nullptr)
      head = newNode;
    else {
      newNode->next = head;
      head = newNode;
    }
  }
  // print all the elements of Linked List
  void printll() {
    if (head == nullptr)
      cout << "Linked List is empty.Nothing to print!" << endl;
    else {
      ListNode *temp = head;
      while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
      }
      cout << "NULL" << endl;
    }
  }

  // Reverse the Linked List using Recursion
  void reverseList() {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    head = reverse(prev, curr);
  }
};
int main() {
  cout << "\n \t \t \t \t \t \t Program to Reverse Linked List Using Recursion"
       << endl;
  cout
      << "\n \t \t \t \t \t \t================================================="
      << endl;

  LinkedList ll;
  ll.push_front(10);
  ll.push_front(20);
  ll.push_front(30);
  cout << "Original Linked List :";
  ll.printll();
  ll.reverseList();
  cout << endl;
  cout << "Reversed Linked List :";
  ll.printll();
}