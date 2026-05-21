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
    bool isPalindrome(ListNode* head) {
        ListNode* leftHead=head;
        ListNode* mid=findMid(head);
        ListNode* rightHead=mid->next;
        mid->next=NULL;
        rightHead=reverseLL(rightHead);
        ListNode* tempL=leftHead, *tempR=rightHead;
        while(tempL!=NULL && tempR!=NULL){
            if(tempL->val!=tempR->val){
                return false;
            }
            tempL=tempL->next;
            tempR=tempR->next;
        }
        return true;
    }
    ListNode* findMid(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

};