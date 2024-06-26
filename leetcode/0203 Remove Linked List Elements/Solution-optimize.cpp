// Vậy bài này bài thêm Node ở đầu : dạng p->next
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

// Dạng p->next
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *term = new ListNode();
        term->next = head;
        ListNode *p = term;

        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }

        return term->next;
    }
};