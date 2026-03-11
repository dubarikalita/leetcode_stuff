class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL ||head->next==NULL)return head;
        ListNode* oddNode = head,*yaad=head->next;
        ListNode* evenNode = head->next;
        
        while (evenNode != NULL && evenNode->next != NULL) {
            oddNode->next = oddNode->next->next;
            oddNode = oddNode->next;
            evenNode->next = evenNode->next->next;
            evenNode = evenNode->next;
        }
        oddNode->next = yaad;

        return head;
    }
};