/**
 * Definition for singly-linked list.
 */

/// TLE:  Time Limit Exceeded

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {

        ListNode *nodeFound = searchNode(head, val);

        while (nodeFound) {
            nodeFound = searchNode(head, val);
            if (nodeFound) {
                ListNode *currentNode = head;
                ListNode *previousNode = head;
                while (currentNode != nullptr) {
                    previousNode = currentNode;
                    currentNode = currentNode->next;
                    if (currentNode == nodeFound) {
                        previousNode->next = currentNode->next;
                        break;
                    }
                }
            }
        }
        return head;
    }
    ListNode *searchNode(ListNode *head, int val) {
        ListNode *currentNode = head;

        while (currentNode != nullptr) {
            if (currentNode->val == val) {
                return currentNode;
            }
            currentNode = currentNode->next;
        }
        return nullptr;
    }
};