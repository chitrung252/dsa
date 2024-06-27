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

// Quan trong thag nextnode lay node + 1 sau do gan nextnode->node = node
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *nextNode = head->next;
        ListNode *newHead = reverseList(nextNode);
        nextNode->next = head;
        head->next = nullptr;
        return newHead;
    }
};