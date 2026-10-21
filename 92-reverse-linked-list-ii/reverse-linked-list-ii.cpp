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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
       ListNode* t = head;
       ListNode* before = dummy;
       int pos = 1;
       while(pos < left){
        before = t;
        t = t->next;
        pos++;
        continue;
       }
       ListNode* curr = t;
       int times = right - left +1;
       ListNode* prev = nullptr;
       while(times--){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
       }

       t->next = curr;
       before->next = prev;

       return dummy->next;






































        // if (!head || left == right) return head;

        // ListNode* dummy = new ListNode(0);
        // dummy->next = head;

        // ListNode* prev = dummy;

        // // Step 1: Move prev to node before 'left'
        // for (int i = 1; i < left; i++) {
        //     prev = prev->next;
        // }

        // // Step 2: Start reversing
        // ListNode* curr = prev->next;

        // for (int i = 0; i < right - left; i++) {
        //     ListNode* nextNode = curr->next;

        //     curr->next = nextNode->next;
        //     nextNode->next = prev->next;
        //     prev->next = nextNode;
        // }

        // return dummy->next;
    }
};