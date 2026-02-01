#include <iostream>
using namespace std;

//creating a class for each Node of Circular Linked List:
class Node{
public :
    int data;
    Node* next;
    
    //creating a parameterized constructor for each node of circular linked list
    Node(int data){
     this->data = data;
     next = NULL;
    }
};

//creating a class of Circular Linked List:
class CircularLinkedList{
    Node* head;
    Node* tail;

public:
    //creating a non-parameterized constructor of circular linked list.
    CircularLinkedList(){
        head = tail = NULL;
    }
   //push(add/insert) the newNode into the beginning(starting) of the Circular Linked List.
    void insertAtHead(int val){
        Node* newNode = new Node(val);//creating a new node of CLL.
        //if our Circular Linked List is empty means head and tail of CLL is now start pointing to the null value.
        if(head == NULL){
           head = tail = newNode;
           tail->next = head;
        } else{
            newNode->next = head;
            head = newNode;
            tail->next = newNode;
        }
    }

    //push(add/insert) the new node at the end(tail) of Circular Linked List.
    void insertAtTail(int val){
        Node* newNode = new Node(val);
         //if the circular Linked list is empty means head and tail both pointing to the null value.
         if(head == NULL || tail == NULL){
               head = tail = newNode;
               tail->next = head;
         } else{
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
         }

    }


    //delete(remove/pop) the node from the beginning(starting)  or at the head of the Circular linked list.
    void deleteAtHead(){
        //when Circular LL is empty
        if(head == NULL){
            cout << "Circular Linked List is empty.Nothing to pop!" << endl;
            return;
        }
        //for single node
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
         //for two or more nodes
        Node* temp = head;
        head = head->next;
        tail->next = head;


        temp->next = NULL;
        delete temp;
    }


    //delete(pop/remove) the last node(tail node) from the Circular Linked List
    void deleteAtTail(){
        //when Circular LL is empty
        if(head == NULL){
            cout << "Circular Linked List is empty.Nothing to pop!" << endl;
            return;
        }
        //for single node
        else if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
         //for two or more nodes
        Node* temp = tail;
        while(tail->next != temp){
            tail = tail->next;
        }
        tail->next = head;


        temp->next = NULL;
        delete temp;
    }
    //print all the elements of Circular Linked List:
    void printCll(){
        if(head == NULL){
            cout << "Circular Linked List is empty.Nothing to print!";
            return;
        }

        cout << head->data << "->";
        Node* temp = head->next;
        
        while(temp != head){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main(){
    CircularLinkedList cll;

    cll.insertAtTail(3);
    cll.insertAtTail(2);
    cll.insertAtTail(1);



    cll.printCll();

    cll.deleteAtTail();
    cll.printCll();

    cll.deleteAtTail();
    cll.printCll();

    cll.deleteAtTail();
    cll.printCll();
    return 0;
}