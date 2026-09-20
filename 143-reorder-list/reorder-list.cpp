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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ;

        // Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Compare both halves
        ListNode* left = head;
        ListNode* right = prev;

        while (right != nullptr) {
            curr = left;
            left = left->next;
            curr->next = right;
            curr = right;
            right = right->next;
            curr->next = left;
        }

        return ;
    }
};