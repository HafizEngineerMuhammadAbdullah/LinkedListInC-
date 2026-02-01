#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
//create a Node Class:
class Node {
public : 

   int data;
   Node* next;
   Node* random;

   //create a constructor for the Node class:
   Node(int data){
     this->data = data;
     next = nullptr;
     random = nullptr;
   }
};

//Create a Linked List Class:
class LinkedList{
   Node* head;

public : 
    //create a constructor for the Linked List class
    LinkedList(){
        head = nullptr;
    }
   //add(push) the data(elements) at the front of the Linked List:
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


   Node* copyList(){
    //create an unordered_map for Linked List 
    unordered_map<Node*,Node*> map;
    //firstly, simply copy all of the nodes from the Old LinkedList 
    Node* newHead = new Node(head->data);
    Node* oldTemp = head->next;
    Node* newTemp = newHead;
    map[head] = newHead;
    while(oldTemp != NULL){
        Node* copyNode = new Node(oldTemp->data);
        map[oldTemp] = copyNode;
        newTemp->next = copyNode;

        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    //recreate the random connections in a new Linked List
    oldTemp = head; newTemp = newHead;
    while(oldTemp != NULL){
       newTemp->random = map[oldTemp->random];//(magical statement)

       oldTemp = oldTemp->next;
       newTemp = newTemp->next;
    }

    return newHead;

   }

   //traverse the whole Linked List and print all of it's elements
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
    
}