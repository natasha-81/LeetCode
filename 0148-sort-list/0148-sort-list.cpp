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
class Solution {
public:
    ListNode* mergetwolists(ListNode* leftNode, ListNode* rightNode) {
        if (leftNode == NULL && rightNode == NULL ) return NULL;
        if (leftNode == NULL && rightNode != NULL) return rightNode;
        if (rightNode == NULL && leftNode != NULL ) return leftNode;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* lefthead = leftNode;
        ListNode* righthead = rightNode;
        ListNode* temp = dummyNode;
        while (lefthead != NULL && righthead != NULL) {
            if (lefthead->val <= righthead->val) {
                temp->next = lefthead;
                temp = lefthead;
                lefthead = lefthead->next;
            }
            else {
                temp->next = righthead;
                temp = righthead;
                righthead = righthead->next;
            }
        }
        if (lefthead != NULL) {
            temp->next = lefthead;
        }
        else {
            temp->next = righthead;
        }
        return dummyNode->next;
    }
    ListNode* findMiddle(ListNode* head) {
        if (head == NULL || head-> next == NULL ) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow -> next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* middle = findMiddle(head);
        ListNode* rightNode = middle->next;
        middle->next=NULL;
        ListNode* leftNode = head;
        leftNode = sortList(leftNode);
        rightNode = sortList(rightNode);
        return mergetwolists(leftNode,rightNode);

    }
};