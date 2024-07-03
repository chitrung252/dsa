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
// My solution
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *node = head;
        ListNode *previousNode = head;
        int length = 0;
        while (node->next != nullptr) {
            length++;
            node = node->next;
        }
        node = head;
        if (length == 0)
            return head;
        k = k < length ? k : k % length;
        // k = length - (k % length);
        cout << "k: " << k << endl;
        cout << "length: " << length << endl;
        if (k == length)
            return head;
        while (k > 0) {
            while (node->next) {
                previousNode = node;
                node = node->next;
                length++;
            }
            node->next = head;
            head = node;
            previousNode->next = nullptr;
            k--;
        }
        return head;
    }
    void print(ListNode *head) {
        if (head == nullptr) {
            cout << "\nArray is empty";
        }
        ListNode *node = head;
        while (node != nullptr) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << "\n";
    }
};