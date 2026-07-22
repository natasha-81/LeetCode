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
    Node* flatten(Node* head) {
        if (head == NULL ) return head;
        Node* current = head;
        while (current != NULL) {
            if (current->child != NULL) {
                Node* nextnode = current->next;
                Node* childHead = flatten(current->child);
                // link childhead to current
                current->next = childHead;
                childHead->prev = current;
                current->child = NULL;
                //find last node after flattening child node
                Node* tail = childHead;
                while (tail->next != NULL) {
                    tail = tail->next;
                }
                //link back to nextnode
                tail->next = nextnode;
                if (nextnode != NULL) {
                    nextnode->prev = tail;
                }
            }
            current = current->next;
        }
        return head;
    }
};