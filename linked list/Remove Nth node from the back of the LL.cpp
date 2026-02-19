class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* fast=head;
        for(int i=0 ; i<n ; i++) fast=fast->next;
        ListNode* slow=head;
         if(fast==NULL)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;     
            return head;
        }
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
       
         ListNode* delnode=slow->next;
         slow->next=slow->next->next;
         delete delnode;
         return head;
        
    }
};
