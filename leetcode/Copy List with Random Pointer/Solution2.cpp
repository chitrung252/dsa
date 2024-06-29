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

class Solution {
public:
    Node *copyRandomList(Node *head) {
        print(head);
        unordered_map<Node *, Node *> mapOldNode;
        Node *newHead = new Node(0);
        Node *newNodeHead = newHead;
        Node *currentNode = head;

        while (currentNode) {
            Node *newNode = new Node(currentNode->val);
            newNodeHead->next = newNode;
            newNodeHead->next->random = currentNode->random;

            mapOldNode[currentNode] = newNode;

            currentNode = currentNode->next;
            newNodeHead = newNodeHead->next;
        }

        newNodeHead = newHead->next;

        while (newNodeHead) {
            if (newNodeHead->random) {
                Node *foundNodeRandom = mapOldNode[newNodeHead->random];
                if (foundNodeRandom) {
                    newNodeHead->random = foundNodeRandom;
                }
            }
            newNodeHead = newNodeHead->next;
        }
        return newHead->next;
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