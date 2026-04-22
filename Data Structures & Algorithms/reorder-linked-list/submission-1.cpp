class Solution {
public:
    // Helper: Get the tail AND the node before it
    ListNode* getTail(ListNode* head, ListNode*& prev) {
        prev = nullptr;
        while (head && head->next) {
            prev = head;
            head = head->next;
        }
        return head;
    }
    
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        ListNode* curr = head;
        
        while (curr && curr->next) {
            // Find tail and the node before it
            ListNode* prev = nullptr;
            ListNode* tail = getTail(curr->next, prev);
            
            // If tail is the next node, we're done (or only 2 nodes left)
            if (tail == curr->next) break;
            
            // Disconnect tail from the list
            if (prev) prev->next = nullptr;
            
            // Insert tail after curr
            ListNode* temp = curr->next;
            curr->next = tail;
            tail->next = temp;
            
            // Move curr forward by 2 (skip the tail we just inserted)
            curr = temp;
        }
    }
};