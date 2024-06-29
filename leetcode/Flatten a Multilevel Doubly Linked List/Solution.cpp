/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *recursive(Node *head) {

        Node *currentNode = head;
        Node *tail = nullptr;

        while (currentNode) {
            Node *nextNode = currentNode->next;
            if (currentNode->child) {
                Node *lastNode = recursive(currentNode->child);

                lastNode->next = nextNode;

                currentNode->next = currentNode->child;

                currentNode->child->prev = currentNode;

                currentNode->child = nullptr;

                currentNode = lastNode->next;

                if (nextNode) {
                    nextNode->prev = lastNode;
                }
                tail = lastNode;

            } else {
                tail = currentNode;
            }
            currentNode = nextNode;
        }
        return tail;
    }

    Node *flatten(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        recursive(head);

        return head;

        // case 1: dont use recursive cant hanlder all examples
        //         Node *nextNode = head;
        //         while(nextNode){

        //             if(nextNode->child){

        //                 Node *nextChildNode = nextNode->child;

        //                 while(nextChildNode->next){

        //                     if(nextChildNode->child){
        //                         Node *lastNextChildNode = nextChildNode->child;
        //                         while(lastNextChildNode->next){
        //                             lastNextChildNode = lastNextChildNode->next;
        //                             .... continue with has child
        //                         }
        //                         lastNextChildNode->next = nextChildNode->next;
        //                         lastNextChildNode->next->prev = lastNextChildNode;

        //                         nextChildNode->next = nextChildNode->child;
        //                         nextChildNode->next->prev = nextChildNode;
        //                         nextChildNode->child = nullptr;
        //                         nextChildNode = lastNextChildNode->next;
        //                     }else{
        //                         nextChildNode = nextChildNode->next;
        //                     }
        //                 }
        //                 nextChildNode->next = nextNode->next;
        //                 nextChildNode->next->prev = nextChildNode;

        //                 nextNode->next = nextNode->child;
        //                 nextNode->next->prev = nextNode;
        //                 nextNode->child = nullptr;
        //                 nextNode = nextChildNode->next;
        //             }else{
        //                 nextNode = nextNode->next;
        //             }
        //         }
        //         print(head);
        //         return head;
    }
};