/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // first , Brute Force Approach
    // TC: O(m * n) , SC :O(1)
    ListNode *slow = headA;
    while (slow != nullptr) {
      ListNode *fast = headB;
      while (fast != nullptr) {
        // Two Linked Lists are said to be intersected if they begin to
        // intersect at the specific node which have the same value in
        // both LL and the intersected node must have same memory
        // reference(address)
        // if the memory addresses are identical (slow == fast), their values
        // are guaranteed to be identical too!
        if (slow->val == fast->val && slow == fast) {
          return slow;
          // break;
        }
        fast = fast->next;
      }
      slow = slow->next;
    }
    return nullptr;

    // second Approach(Using Hash Set)
    // TC: O(m + n), SC: O(m)
    set<ListNode *> s;
    ListNode *slow = headA;
    while (slow != nullptr) { // TC: O(m)
      s.push(slow);
      slow = slow->next;
    }

    while (fast != nullptr) { // TC: O(n)
      // if the condition meet it means that the node in both the list (listA &
      // listB ) are same that are pointing to the same memory location(memory
      // address)
      if (s.find(fast) != s.end()) {
        break;
      }
    }
    return fast;
  }
  // intersection means :
  // Same Node
  // Same Memory Address
  // Keep moving until:

  // 1. They meet at the intersection node
  // OR
  // 2. Both become NULL
  // handles both cases automatically:
  // ✓ Intersection found
  // ✓ No intersection found
  // Same address ⇒ Same node ⇒ Intersection found.

  // Two linked lists intersect only when they share the same node in memory
  // .Nodes can have identical values but still be different
  // objects.Therefore, we compare node addresses(pA == pB) rather than
  // node values(pA->val == pB->val)
  .
};
int main() {}