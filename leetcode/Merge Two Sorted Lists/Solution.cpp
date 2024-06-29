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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *term = new ListNode();
        ListNode *head = term;

        while (list1 || list2) {

            if (list1 && list2) {

                if (list1->val < list2->val) {
                    term->next = list1;
                    list1 = list1->next;
                } else {
                    term->next = list2;
                    list2 = list2->next;
                }
                term = term->next;

            } else if (list1 && list2 == nullptr) {
                term->next = list1;
                break;
            } else {
                term->next = list2;
                break;
            }
        }
        return head->next;
    }
};