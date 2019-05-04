/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Runtime: 28 ms, faster than 97.00% of C++ online submissions for Add Two Numbers.
// Memory Usage: 10.5 MB, less than 98.60% of C++ online submissions for Add Two Numbers.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* head = NULL, *cur = head, *tail = head;
        ListNode* p1 = l1, *p2 = l2;
        int carry = 0, val = 0;
        while(p1 !=NULL && p2 != NULL) {
            val = p1->val + p2->val + carry;
            carry = val / 10;
            val = val % 10;
            p1 = p1->next;
            p2 = p2->next;
            cur = new ListNode(val);
            if(head == NULL) {
                head = cur;
                tail = cur;
            } else {
                tail->next = cur;
                tail = cur;
            }
            
        }
        if(p1 == NULL && p2 != NULL) {
            while(carry != 0 && p2 != NULL) {
                val = p2->val + carry;
                carry = val / 10;
                val = val % 10;
                cur = new ListNode(val);
                tail->next = cur;
                tail = cur;
                p2 = p2->next;
            }
            tail->next = p2;
        }
        if(p1 != NULL && p2 == NULL) {
            while(carry != 0 && p1 != NULL) {
                val = p1->val + carry;
                carry = val / 10;
                val = val % 10;
                cur = new ListNode(val);
                tail->next = cur;
                tail = cur;
                p1 = p1->next;
            }
            tail->next = p1;
        }
       
        if(carry > 0) {
            int val = carry;
            cur = new ListNode(val);
            tail->next = cur;
            tail = cur;
        }
        return head;
    }
};
