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

// asign head is nullptr using 3th parameter
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head.next == nullptr) {
            return head;
        }
        ListNode *currentNode = head;
        head = nullptr;

        while (currentNode) {
            ListNode *nextNode = currentNode->next;
            currentNode->next = head;
            head = currentNode;
            currentNode = nextNode;
        }
        return head;
    }
};