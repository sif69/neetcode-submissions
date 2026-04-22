class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Count the length
        ListNode* temp = head;
        int length = 0;
        while(temp != NULL) {
            length++;
            temp = temp->next;
        }
        
        // Step 2: Handle edge case - removing the head
        if(n == length) {
            return head->next;
        }
        
        // Step 3: Find the node BEFORE the one to remove
        temp = head;
        for(int i = 1; i < length - n; i++) {
            temp = temp->next;
        }
        
        // Step 4: Remove the nth node
        temp->next = temp->next->next;
        
        return head;
    }
};