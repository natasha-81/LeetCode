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
    ListNode* deleteMiddle(ListNode* head) {
        int length = 0;
        ListNode* temphead = head;
        while (temphead != NULL) {
            temphead=temphead->next;
            length++;
        }
        int middle = (length/2);
        if (head == NULL || head->next==NULL) return NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            middle--;
            if (middle == 0) {
                break;
            }
            temp = temp->next;
        }
        ListNode* delnode = temp->next;
        temp->next = temp->next->next;
        delete delnode;
        return head;
    }
};