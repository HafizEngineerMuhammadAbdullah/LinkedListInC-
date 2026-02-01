#include <iostream>
#include <unordered_map>
using namespace std;
// create a class Node for Doubly Linked List
struct Node {
public:
  int key;
  int value;
  Node *next;
  Node *prev;

  // create a parameterized constructor for Node class
  Node(int key, int val) {
    this->key = key;
    this->value = val;
    this->next = this->prev = NULL;
  }
};

// create a LRU Cache class
class LRUCache {
private:
  int capacity;
  unordered_map<int, Node *> cacheMap; // key and node pointer
  Node *head;                          // dummy head
  Node *tail;                          // dummy tail

  // method to remove a node from the doubly linked list
  void removeNode(Node *node) {
    Node *oldPrev = node->prev;
    Node *oldNext = node->next;
    oldPrev->next = oldNext;
    oldNext->prev = oldPrev;
  }

  // method to insert a node in the front(head->next) of the Linked List!
  void addToFront(Node *newNode) {
    Node *node = head->next;
    head->next = newNode;
    node->prev = newNode;

    // establish a connection between newNode,head and node
    newNode->prev = head;
    newNode->next = node;
  }

public:
  // parameterized constructor
  LRUCache(int capacity) {
    this->capacity = capacity;
    head = new Node(-1, -1); // dummy head
    tail = new Node(-1, -1); // dummy tail
    head->next = tail;
    tail->prev = head;
  }

  // Destructor to clean up memory
  ~LRUCache() {
    Node *temp = head;
    while (temp != NULL) {
      Node *nextNode = temp->next;
      delete temp;
      temp = nextNode;
    }
    cacheMap.clear(); // Optional, but good practice
  }

  // implement a get method
  int get(int key) {
    // if key does't exist in the map.
    if (cacheMap.find(key) == cacheMap.end()) {
      return -1; // key not found
    }
    Node *node = cacheMap[key];
    int ans = node->value;
    cacheMap.erase(key);
    removeNode(node);
    addToFront(node);
    cacheMap[key] = node;
    return ans;
  }

  // implement a put method
  void put(int key, int value) {
    // if the same key exist in the map but it's value is changed
    if (cacheMap.find(key) != cacheMap.end()) {
      Node *node = cacheMap[key];
      cacheMap.erase(key);
      removeNode(node);
    }
    // if the capacity is reached
    if (cacheMap.size() == capacity) {
      // remove LRU item
      cacheMap.erase(tail->prev->key);
      removeNode(tail->prev);
    }
    // add newNode
    Node *newNode = new Node(key, value);
    addToFront(newNode);
    cacheMap[key] = newNode;
  }
};

int main() {
  cout << "\n \t \t \t \t \t \t Design and Implement an LRU cache!" << endl;
  cout << "\n \t \t \t \t \t \t======================================" << endl;

  // create an object of class LRUCache
  LRUCache lru(2);

  lru.put(1, 1);
  lru.put(2, 2);
  cout << lru.get(1) << endl;
  lru.put(3, 3);
  cout << lru.get(2) << endl;
  lru.put(4, 4);
  cout << lru.get(1) << endl;
  cout << lru.get(3) << endl;
  cout << lru.get(4) << endl;
  return 0;
}