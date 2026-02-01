#include <iostream>
using namespace std;
// firstly,create a node class:
class Node
{
public:
    int data;
    Node *next;
    // create a non-parameterized constructor for Node class:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// create a LinkedList class:
class LinkedList
{

    Node *head;

public:
    // create a non-parameterized constructor for LinkedList class:
    LinkedList()
    {
        head = NULL;
    }

    // add(push) the elements(data) at the front of linked list:
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        // if the head is pointing towards the NULL value this means that our Linked List is empty:
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        // else if the head is not pointing towards the NULL value this means that our Linked List has already atleast one node:
        newNode->next = head;
        head = newNode;
    }

    // print all the elements of Linked List:
    void printll()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Find the middle of the linked list for even and odd nodes of the Linked List:
    Node* findMiddle()//TC:O(n),SC:O(1)
    {

        if (head == NULL)
        {
            cout << "Linked List is empty!" << endl;
            return NULL;
        }
        // initialize both the slow and fast pointer with a value of headptr of the linked list
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            //move the slow pointer by step1
            slow = slow->next;       // increment the slow pointer by +1
            //move the fast pointer by step2
            fast = fast->next->next; // increment the fast pointer by +2
        }
        return slow;
    }
};

int main()
{
    LinkedList list;
    list.push_front(40);
    list.push_front(30);
    list.push_front(20);
    list.push_front(10);
    list.printll();
    Node* mid = list.findMiddle();
    if(mid != NULL){
    cout << "Middle Element : " << mid->data << endl;
    }
    return 0;
}