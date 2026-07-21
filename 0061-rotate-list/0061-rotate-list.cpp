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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k==0) return head;
        int length = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
            length++;
        }
        tail->next = head; //circular list
        k = k%length;
        int movestillNewTail = length - k;
        ListNode* newTail = head;
        for (int i=1; i<movestillNewTail; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next; //new head 
        newTail->next = NULL;
        return newHead;
    }
};