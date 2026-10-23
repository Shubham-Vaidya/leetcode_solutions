/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int length = 0;
        ListNode* count = head;
        while(count != NULL){
            length++;
            count = count->next;
        }
        k = k%length;
        if(k == 0) return head;
        int end = length - k -1;
        ListNode* newHead = head;
        ListNode* curr = head;
        ListNode* newEnd = head;
        int check = 0;
        while(curr->next != NULL){
            if(check == end){
                newEnd = curr; 
                newHead = curr->next;
            } 
            curr = curr->next;
            check++;
            
        } 
        curr->next = head;
        newEnd->next = NULL;

        return newHead;



























        // // Edge cases
        // if (!head || !head->next || k == 0) return head;

        // // Step 1: Find length and tail
        // ListNode* curr = head;
        // int length = 1;
        // while (curr->next) {
        //     curr = curr->next;
        //     length++;
        // }

        // // Step 2: Make circular list
        // curr->next = head;

        // // Step 3: Optimize k
        // k = k % length;

        // // Step 4: Find new tail
        // int steps = length - k;
        // curr = head;
        // for (int i = 0; i < steps - 1; i++) {
        //     curr = curr->next;
        // }

        // // Step 5: Break the circle
        // ListNode* newHead = curr->next;
        // curr->next = NULL;

        // return newHead;
    }
};