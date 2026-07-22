struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* node = head; // create a pointer called node at head "node changes but head stays the same so we can still have somewhere to start our list"
    while(node != NULL && node->next != NULL) {
        if(node->val == node->next->val) { // if the current node = the next node
            struct ListNode* duplicate = node->next; // make the next node "duplicate"
            node->next = node->next->next; // then make the next node = to the node after it
            free(duplicate); // this program "frees memory" basically deletes it.
        }
        else {
            node = node->next;
        }
    }
    return head;
}
