#include <iostream>
using namespace std;

// Create a node class:
class Node {

public:
  int data;
  Node *next;

  // Create a constructor for a Node Class
  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

// create a class called Linked List:
class LinkedList {
  Node *head;
  Node *tail;

public:
  // create a constructor for Linked List:
  LinkedList() { head = tail = NULL; }

  // push(add) the elements at the front of the LinkedList
  void push_front(int val) {
    Node *newNode = new Node(val);
    // if the head of LL is pointing towards the Nullptr means there is no node
    // still exist in the Linked List:
    if (head == NULL) {
      head = tail = newNode;
      return;
    }
    // else the head of the ll is pointing towards the front element of the ll
    // means there is at least one node available(present) in the ll.
    newNode->next = head;
    head = newNode;
  }

  // push(add) the element at the end of the linked list
  void push_back(int val) {
    Node *newNode = new Node(val);
    // if the head of LL is pointing towards the Nullptr means there is no node
    // still exist in the Linked List:
    if (head == NULL) {
      head = tail = newNode;
      return;
    }
    // else the head of the ll is pointing towards the front element of the ll
    // means there is at least one node available(present) in the ll.
    tail->next = newNode;
    tail = newNode;
  }

  // print all the elements of the LinkedList
  void printll() {
    Node *temp = head;

    while (temp != NULL) {
      cout << temp->data << "->";
      temp = temp->next;
    }

    cout << "NULL" << endl;
  }

  // Reversing a LinkedList
  Node *reverseLL(Node *head) {
    // if the head of LL is pointing towards the Nullptr means there is no node
    // still exist in the Linked List:
    if (head == NULL) {
      cout << "Linked List is empty!" << endl;
      return NULL;
    }

    // using three pointer Approach:
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;

      // update the pointers for the next iterations
      prev = curr;
      curr = next;
    }
    return prev;
  }

  Node *addTwoLinkedList(Node *head1, Node *head2) {
    Node *temp1 = reverseLL(head1);
    Node *temp2 = reverseLL(head2);
    LinkedList ll;

    int oldFd = 0;
    int res = 0;
    int firstDigit;
    int secDigit;
    // while (temp1 != NULL && temp2 != NULL) {
    //   res = temp1->data + temp2->data;
    //   firstDigit = res / 10;
    //   secDigit = res % 10;
    //   ll.push_back(secDigit + oldFd);
    //   oldFd = firstDigit;
    //   temp1 = temp1->next;
    //   temp2 = temp2->next;
    // }

    // if (temp1 != NULL) {
    //   while (temp1 != NULL) {
    //     res = oldFd + temp1->data;
    //     firstDigit = res / 10;
    //     secDigit = res % 10;
    //     ll.push_back(secDigit);
    //     oldFd = firstDigit;
    //     temp1 = temp1->next;
    //   }
    //   if (oldFd != 0) {
    //     ll.push_back(oldFd);
    //   }
    // } else if (temp2 != NULL) {
    //   while (temp2 != NULL) {
    //     res = oldFd + temp2->data;
    //     firstDigit = res / 10;
    //     secDigit = res % 10;
    //     ll.push_back(secDigit);
    //     oldFd = firstDigit;
    //     temp2 = temp2->next;
    //   }
    //   if (oldFd != 0) {
    //     ll.push_back(oldFd);
    //   }
    // }
    // if (oldFd != 0) {
    //   ll.push_back(oldFd);
    // }
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL || carry != 0) {
      int val1 = temp1 ? temp1->data : 0;
      int val2 = temp2 ? temp2->data : 0;
      int res = val1 + val2 + carry;
      carry = res / 10;
      int digit = res % 10;

      ll.push_back(digit);

      if (temp1)
        temp1 = temp1->next;
      if (temp2)
        temp2 = temp2->next;
    }

    ll.printll();
    return ll.head;
  }

  //   helper function of Add two Linked List
  void addTwoLinkedList() {
    LinkedList ll1;
    LinkedList ll2;
    // ll1.push_front(0);
    // ll1.push_front(3);
    // ll1.push_front(4);
    // ll1.push_front(2);
    // ll1.push_front(9);
    // ll1.push_front(9);
    // ll1.push_front(9);
    // ll1.push_front(9);
    // ll1.push_front(9);
    // ll1.push_front(9);
    // ll1.push_front(9);
    ll1.push_front(9);
    ll1.push_front(4);
    ll1.push_front(2);
    // ll.push_front()
    ll1.printll();
    // ll2.push_front(9);
    // ll2.push_front(9);
    // ll2.push_front(9);
    // ll2.push_front(9);
    ll2.push_back(5);
    ll2.push_back(6);
    ll2.push_back(4);
    ll2.push_back(9);
    // ll2.push_back(5);
    // ll2.push_back(6);
    // ll2.push_back(4);
    // ll2.push_back(0);
    ll2.printll();
    addTwoLinkedList(ll1.head, ll2.head);
  }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* resultHead = nullptr;
    ListNode* resultTail = nullptr;
    ListNode* reverseLL(ListNode* head) { // TC:O(n)
        if (head == NULL) {
            cout << "LinkedList is Empty!" << endl;
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = reverseLL(l1);
        ListNode* temp2 = reverseLL(l2);

        int carry = 0;
        int res;
        int firstDigit;
        int secDigit;
        while (temp1 != NULL && temp2 != NULL) {
            res = temp1->val + temp2->val;
            firstDigit = res / 10;
            secDigit = res % 10;
            ListNode* newNode = new ListNode(secDigit + carry);
            //   ll.push_back(secDigit + carry);
            if (resultHead == nullptr || resultTail == nullptr) {
                resultHead = resultTail = newNode;
            } else {
                resultTail->next = newNode;
                resultTail = newNode;
            }
            carry = firstDigit;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if (temp1 != NULL) {
            while (temp1 != NULL) {
                res = carry + temp1->val;
                firstDigit = res / 10;
                secDigit = res % 10;
                ListNode* newNode = new ListNode(secDigit);
                if (resultHead == nullptr) {
                    resultHead = resultTail = newNode;
                } else {
                    resultTail->next = newNode;
                    resultTail = newNode;
                }
                carry = firstDigit;
                temp1 = temp1->next;
            }
            if (carry != 0) {
                ListNode* newNode = new ListNode(carry);
                if (resultHead == nullptr) {
                    resultHead = resultTail = newNode;
                } else {
                    resultTail->next = newNode;
                    resultTail = newNode;
                }
            }
        } else if (temp2 != NULL) {
            while (temp2 != NULL) {
                res = carry + temp2->val;
                firstDigit = res / 10;
                secDigit = res % 10;
                ListNode* newNode = new ListNode(secDigit);
                if (resultHead == nullptr) {
                    resultHead = resultTail = newNode;
                } else {
                    resultTail->next = newNode;
                    resultTail = newNode;
                }
                carry = firstDigit;
                temp2 = temp2->next;
            }
            if (carry != 0) {
                ListNode* newNode = new ListNode(carry);
                if (resultHead == nullptr) {
                    resultHead = resultTail = newNode;
                } else {
                    resultTail->next = newNode;
                    resultTail = newNode;
                }
            }
            if (carry != 0) {
                ListNode* newNode = new ListNode(carry);
                if (resultHead == nullptr) {
                    resultHead = resultTail = newNode;
                } else {
                    resultTail->next = newNode;
                    resultTail = newNode;
                }
            }
        }

        return resultHead;
    }
};
int main() {
  LinkedList lll;
  lll.addTwoLinkedList();
}