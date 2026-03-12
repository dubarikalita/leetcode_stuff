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
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* temp=head;
        ListNode* curr=head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }

        int pos=len/2;
        for(int i=1;i<pos;i++){
            curr=curr->next;
        }
        curr->next=curr->next->next;
        
        return head;

   }
};