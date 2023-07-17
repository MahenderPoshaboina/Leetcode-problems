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
    ListNode* reverseList(ListNode* head) {
        ListNode *currentnode=head, *nextnode=head, *prevnode=0;
        while(nextnode!=0)
        {
            nextnode=nextnode->next;
            currentnode->next=prevnode;
            prevnode=currentnode;
            currentnode=nextnode;
        }
        return prevnode;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1= reverseList(l1);
        l2= reverseList(l2);
        int carry=0;
        ListNode *dummy=new ListNode(0);
        ListNode *head=dummy;
        while( l1 || l2)
        {
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode *temp= new ListNode(sum);
            dummy->next=temp;
            dummy=dummy->next;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        }
        if(carry)
            {
                dummy->next=new ListNode(carry);
        }  
        head=reverseList(head);
        ListNode* temp=head;
        while(temp->next->next){
            temp= temp->next;
        }
        temp->next= NULL;
        return head;
    }
};