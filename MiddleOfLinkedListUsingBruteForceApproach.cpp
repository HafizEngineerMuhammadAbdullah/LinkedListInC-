#include<iostream>
using namespace std;
//create a Node Class:
class Node {
public : 

   int data;
   Node* next;

   //create a constructor for the Node class:
   Node(int data){
     this->data = data;
     next = nullptr;
   }
};

//Create a Linked List Class:
class LinkedList{
   Node* head;

public : 
    // constructor
    LinkedList(){
        head = nullptr;
    }
   //add(push) the data(elements) into the Linked List:
   void push_front(int val){
    //create a new node
     Node* newNode = new Node(val);
    //if the head of the Linked List is pointing towards the NULL value means there is no node still exist in the Linked List
    if(head == nullptr){
      head = newNode;
      return;
    } 
    newNode->next = head;
    head = newNode;
    return;
   }

   //find the middle of the Linked List:
   Node* findMiddle(){//TC:O(n),SC:O(1)
    
    //if the head of the Linked List is pointing towards the NULL value means there is no node still exist in the Linked List
    if (head == nullptr)
        {
            cout << "Linked List is empty!" << endl;
            return nullptr;
        }
        //initialize the size with 0.
    int size = 0;
    Node* temp = head;
    while(temp != nullptr){
     size++;
     temp = temp->next;
   }
   temp = head;
   for(int i = 0; i < size/2; i++){
    temp = temp->next;
   }

    return temp;
}

   void printll(){
    Node* temp = head;
     
    while(temp != nullptr){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
   }


};
int main(){
    LinkedList ll;
    ll.push_front(43);
    ll.push_front(23);
    ll.push_front(13);
    ll.push_front(384);
    ll.printll();
    Node* mid = ll.findMiddle();
    cout << "Middle of the Linked List will be : " << mid->data <<endl;
    
}