#include<iostream>
using namespace std;

class Node{

public : 

   int data;
   Node* next;

   //create a constructor for the Node class:
   Node(int data){
     this->data = data;
     next = nullptr;
   }

};

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


    //print all the elements(data) of the linked list.
    void printll(){
    Node* temp = head;
     
    while(temp != nullptr){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
   }

   //Using Slow And Fast Pointer Approach Check whether there is a cycle contain in the Linked List or not.
   bool hasCycle(){//TC:O(n),SC:O(1)
    //initialize both the pointers(i.e: slow and fast) with a value head.
      Node* slow = head;
      Node* fast = head;

      
      while(fast != NULL && fast->next != NULL){//handle both the even and odd number of linked list edge cases
           slow = slow->next;
           fast = fast->next->next;
           if(slow == fast){
               return true;
           }
      }
      return false;

   } 


    //detect the initial(beginning) node of the cycle and return the beginning node of the cycle if the cycle is present otherwise return NULL.  
    Node* detectCycle(){

    //initialize both the pointers(slow and fast) value with the value head. 
      Node* slow = head;
      Node* fast = head;
      bool isCycle = false;
      
      //check whether the cycle is present(exist) in the linked list or not.
      while(fast != NULL && fast->next != NULL){

           slow = slow->next;
           fast = fast->next->next;

           //if the slow and fast pointer pointing towards the same node,this means cycle(loop) exist in the LinkedList
           if(slow == fast){
             isCycle = true;
             break;//preserve the fast pointer value  
           }
         
      }

      //if the cycle doesn't exist(present) then return NULL.
      if(!isCycle){
          return NULL;
      }

      //Cycle is present means to return the starting(beginning) node of the cycle.
      
      //set the slow pointer with the value head
      slow = head;
      //to remove the cycle in the linked list.
      //initialize the previous variable with the value NULL
      Node* prev = NULL;

      while(slow != fast){

        slow = slow->next;
        //update the prev value with the fast
        prev = fast;
        fast = fast->next;
      }
      prev->next = NULL;//remove the cycle
      //now, slow == fast :
      return slow;

   }

};
int main(){
    LinkedList list;
    list.push_front(50);
    list.push_front(40);
    list.push_front(30);
    list.push_front(20);
    list.push_front(10);

    list.printll();
    if(list.hasCycle()){
        cout << "Linked has a cycle or loop" << endl;
    } else{
        cout << "Linked doesn't have a cycle or loop" << endl;
    }

    Node* detectCycle = list.detectCycle();
    cout << detectCycle << endl;

}