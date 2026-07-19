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
    bool isPalindrome(ListNode* head) {
         if (!head || !head->next) return true;

    // Step 1: Find middle
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    ListNode* prev = NULL;
    ListNode* curr = slow->next;

    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Step 3: Compare
    ListNode* first = head;
    ListNode* second = prev;

    while (second) {
        if (first->val != second->val) return false;
        first = first->next;
        second = second->next;
    }

    return true;
    }
};