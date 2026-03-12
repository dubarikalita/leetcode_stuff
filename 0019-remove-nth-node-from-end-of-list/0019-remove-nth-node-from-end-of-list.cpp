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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* temp1=head;
        ListNode* temp2=head;
        int len=0;
        while(temp1!=NULL){
            len++;
            temp1=temp1->next;
        }
        if(n==len) return head->next;
        int pos=len-n;
        for(int i=1;i<pos;i++){
            temp2=temp2->next;
        }
        temp2->next=temp2->next->next;
        return head;
    }
};