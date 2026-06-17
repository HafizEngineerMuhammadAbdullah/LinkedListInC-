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
    // TC:O(n) , SC:O(1)
    // initialize the head & tail pointer as nullptr as the new LL is empty
    // initially
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    // function to  push the newNode at the end(back) of LL
    void push_back(int val) {
        // create a newNode of LL
        ListNode* newNode = new ListNode(val);
        // if LL is empty means when head is pointing to NULL value
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        // point the tail pointer to point to newNode(new tail) of LL
        tail->next = newNode;
        // update the tail pointer to point to the new tail of LL
        tail = newNode;
    }

    // function to combine the numbers of each node of a LL into a variable
    int addNumbers(ListNode* listHead) { // TC:O(n) where n is the size of list
        int num = 0;
        ListNode* curr = listHead;
        // loop through Linked List(scan the list)
        while (curr != nullptr) {
            num = num * 10 + curr->val;
            curr = curr->next;
        }

        return num;
    }

    // function to reverse the integer so that we could conveniently(easily) add
    // two numbers
    int reverseInteger(int number) { // TC:O(n) where n is the size of integer
        int reversedNum = 0;

        while (number != 0) {
            // extract the last digit from the original integer
            int lastDigit = number % 10;
            reversedNum =
                reversedNum * 10 + lastDigit; // append the last digit of
                                              // original Number in reversedNum
            number /= 10; // integer division remove(discard/eliminate/delete)
                          // the decimal part(here remove the last digit of
                          // original number)
        }
        return reversedNum;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = addNumbers(l1);
        int num2 = addNumbers(l2);

        int reverseNum1 = reverseInteger(num1);
        int reverseNum2 = reverseInteger(num2);

        int num3 = reverseNum1 + reverseNum2;
        if (num3 != 0) {
            while (num3 != 0) {
                // pick the last digit from num3
                int lastDigit = num3 % 10;
                // push the last digit value into new LL
                push_back(lastDigit);

                num3 /= 10; // remove the last digit from num3
            }
        } else {
            return new ListNode(0);
        }
        // tail->next = nullptr;//point the tail node to nullptr
        return head; // return the head of the sum of two LL in reverse form
    }
};



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
    // TC:O(max(m,n)) , SC:O(max(m,n))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // create a dummy Node for safely insertion into a new LinkedList
        ListNode* dummyNode = new ListNode(0);
        ListNode* tail = dummyNode;

        int carry = 0;
        // Continue until both lists & carry exhausted
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            // add the value of l1 into sum & update l1
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // add the value of l2 into sum & update l2
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // extract carry value from sum
            carry = sum / 10;

            ListNode* newNode = new ListNode(
                sum %
                10); // extract the last digit of sum & insert into new Node

            tail->next = newNode;
            tail = newNode;
        }

        ListNode* newHead = dummyNode->next;
        delete dummyNode;

        return newHead;
    }
};