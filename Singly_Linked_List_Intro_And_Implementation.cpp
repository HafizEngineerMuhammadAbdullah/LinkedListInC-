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

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }



    // push/add the data(elements) at the front of linked list.
    void push_front(int val) // TC:O(1)
    {
        Node *newNode = new Node(val); // create a dynamic object
        // case 1:
        // if the linked list is empty(NULL)
        if (head == NULL)
        {
            head = tail = newNode; // head and tail pointer points towards the same node(first node).
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }


    // push/add the data(elements) at the end of linked list.
    void push_back(int val) // TC:O(1)
    {
        Node *newNode = new Node(val); // create a dynamic object
        if (head == NULL)
        {
            head = tail = newNode; // head and tail pointer points towards the same node(first node).
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }


    // pop(delete/remove) the data(elements) from the front of the Linked list
    void pop_front() // TC:O(1)
    {
        // if my linked list is empty(head => NULL)
        if (head == NULL)
        {
            cout << "Linked List is empty.Nothing to pop" << endl;
            return;
        }
        // else my linked list is not empty(there is at least one node available in linked list).
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }


    // pop(delete/remove) the data(elements) from the end of linked list
    void pop_back() // TC:O(n)
    {
        if (head == NULL)
        {
            cout << "Linked List is empty.Nothing to pop" << endl;
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
        // tail = temp;
        // tail->next = NULL;
        // temp = temp->next;
        // delete temp;
    }


    // insert the data(elements) at any position of linked list.
    void insert(int val, int pos) // TC:O(n)
    {
        if (pos < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Position is greater than the length of linked list" << endl;
                return;
            }
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }


    // search for a key in linked list and return its index.
    int search(int key) // TC:O(n)
    {
        Node *temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    
    // print all the elements of linked list.
    void printll() // TC:O(n)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << " [ " << temp->data << " ] -> ";
            temp = temp->next;
        }
        cout << "[ NULL ]" << endl;
    }
};
int main()
{

    List ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.insert(25, 1);
    cout << ll.search(25) << endl;
    ll.printll();
    return 0;
}