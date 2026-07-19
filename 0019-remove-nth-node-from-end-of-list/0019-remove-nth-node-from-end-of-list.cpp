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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temphead = head;
        while (temphead != NULL) {
            temphead = temphead->next;
            count++;
        }
        int knode = count-n+1;
        if (head ==  NULL) return head;
        if (knode == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int currentcnt = 0;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            currentcnt++;
            if (currentcnt == knode) {
                prev->next = prev->next->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};