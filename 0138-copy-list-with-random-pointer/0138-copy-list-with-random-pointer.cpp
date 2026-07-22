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
    Node* copyRandomList(Node* head) {
        if (head == NULL) return head;
        // insert copy nodes first
        Node* temp = head;
        while (temp != NULL) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }
        // set random pointers of copied nodes
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            temp=temp->next->next;
        }
        // separate copied and original lists
        Node* dummy = new Node (0);
        Node* copyHead = dummy;
        temp = head;
        while (temp != NULL) {
            Node* copy = temp->next;
            copyHead->next = copy;
            copyHead = copy;
            temp->next = copy->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};