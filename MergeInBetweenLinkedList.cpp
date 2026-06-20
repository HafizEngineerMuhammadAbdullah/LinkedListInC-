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
    // TC:O(m + n) where m & n are the size of list1 & list2 respectively ,
    // SC:O(1)
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1;
        int idx = 0; // idx => track the position of temp variable(postion of
                     // node) in the list1
        // move temp1 to a - 1th index node
        while (idx < a - 1) {
            temp1 = temp1->next;
            idx++;
        }

        ListNode* curr = temp1->next;
        idx++;
        // delete the index one by one that are lie in the range [a,b] including
        // a & bth node means remove those idx node which are lie in the range
        // [a,b] i.e: a <= node idx <= b
        // delete those node whose index lies in the range from ath index to bth
        // index node
        while (idx < b + 1) {
            // preserve the delete node address in the form of pointer
            ListNode* nodeToDelete = curr;
            curr = curr->next; // update the curr to next node
            delete nodeToDelete;
            idx++;
        }

        ListNode* temp2 =
            curr; // because we want b+1 idx node address so that we could put
                  // list2 in the place of deleted node

        // tail of list2
        ListNode* tail = list2;
        // now find the tail of list2 ll
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        temp1->next = list2;
        tail->next = temp2;

        // return the modified list1 after merging list2 in place of removed
        // node
        return list1;
    }
};