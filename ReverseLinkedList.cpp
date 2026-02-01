#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // push(add) the elements to the front of LinkedList:
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        // if the Linkedlist is empty(head points toward the NULL value) means there is no node still exist in the LinkedList.
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        // else if head is not pointing towards the NULL value means the LinkedList is not empty,i.e. there is at least one node available in the LinkedList.
        else
        {
            newNode->next = head;
            head = newNode;
            return;
        }
    }

    // print all the elements(data) of LinkedList
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
    // Reverse all the elements of Linked list:
    void reverseLinkedList()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *nextptr = NULL;
        while (curr != NULL)
        {
             nextptr = curr->next;
             curr->next = prev;

             prev = curr;
             curr = nextptr;
        }
        head = prev;
    }
};

int main()
{
    LinkedList list;
    list.push_front(30);
    list.push_front(20);
    list.push_front(10);
    list.printll();
    list.reverseLinkedList();
    list.printll();
    return 0;
}