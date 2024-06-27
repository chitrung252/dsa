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
// Cant work with odd array
class Solution {
public:
    int getLength(ListNode *head) {
        int index = 0;
        ListNode *node = head;
        while (node) {
            node = node->next;
            index++;
        }
        return index;
    }

    bool isPalindrome(ListNode *head) {
        int length = getLength(head);
        if (length == 1) {
            return true;
        }
        if (length % 2 == 0) {
            int middle = length / 2;
            int index = 0;
            ListNode *halfOne = new ListNode();
            ListNode *nodeHalfOne = halfOne;

            ListNode *halfTwo = new ListNode();
            ListNode *nodeHalfTwo = halfTwo;

            while (head) {
                ListNode *next = head->next;
                head->next = nullptr;
                if (index < middle) {
                    nodeHalfOne->next = head;
                    nodeHalfOne = nodeHalfOne->next;
                } else {
                    nodeHalfTwo->next = head;
                    nodeHalfTwo = nodeHalfTwo->next;
                }
                index++;
                head = next;
            }

            ListNode *halfOneReverse = reverseList(halfOne->next);
            ListNode *nodeA = halfOneReverse;
            ListNode *nodeB = halfTwo->next;
            bool isValid = true;

            while (nodeA != nullptr) {
                if (nodeA->val != nodeB->val) {
                    isValid = false;
                    break;
                }
                nodeA = nodeA->next;
                nodeB = nodeB->next;
            }
            return isValid;
        }

        return false;
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