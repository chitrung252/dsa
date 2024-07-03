/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// only with different value
class Solution {
public:
    Node *copyRandomList(Node *head) {
        print(head);
        Node *newHead = new Node(0);
        Node *newNodeHead = newHead;
        Node *currentNode = head;
        while (currentNode) {
            Node *newNode = new Node(currentNode->val);
            newNodeHead->next = newNode;
            currentNode = currentNode->next;
            newNodeHead = newNodeHead->next;
        }

        currentNode = head;
        newNodeHead = newHead->next;
        while (currentNode) {

            if (currentNode->random) {
                Node *nodeFound = search(newHead->next, currentNode->random->val);
                if (nodeFound) {
                    newNodeHead->random = nodeFound;
                }
            }
            newNodeHead = newNodeHead->next;
            currentNode = currentNode->next;
        }
        return newHead->next;
    }

    Node *search(Node *head, int val) {
        Node *node = head;
        while (node) {
            if (node->val == val) {
                return node;
            }
            node = node->next;
        }
        return nullptr;
    }

    void print(Node *head) {
        if (head == nullptr) {
            cout << "\nArray is empty";
        }
        Node *node = head;
        while (node != nullptr) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << "\n";
    }
};