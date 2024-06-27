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

// Chưa hiểu lắm sài two pointer
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != nullptr) {
            slow = slow->next;
        }

        slow = reverseList(slow);

        while (slow != nullptr && head->val == slow->val) {
            head = head->next;
            slow = slow->next;
        }
        return slow == nullptr;
    }
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
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