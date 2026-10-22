class Solution {
public:

    void reverse(ListNode* head, int times){
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(times--){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
            return;
    }

    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        int size = 2;
        ListNode* left = head;
        ListNode* res = NULL;
        ListNode* prevleft = NULL;
        ListNode* right;

        while(true){
            right = left;
            for(int i = 0 ; i < size-1 ; i++){
                if(right == NULL)
                    break;
                right = right->next;
            }

            if(right){
                ListNode* nextleft = right->next;
                reverse(left,size);
                if(prevleft)
                    prevleft->next = right;
                prevleft = left;
                if(res == NULL)
                    res = right;
                left = nextleft;
            }
            else{
                if(prevleft){
                    prevleft->next = left;
                }
                if(res == NULL)
                    res = left;
                break;
            }
           
        }
         return res;
    }
};