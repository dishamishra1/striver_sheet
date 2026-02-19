class Solution {
public:
    ListNode* findmiddle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow; 
    } 

    ListNode* mergelist(ListNode* list1 , ListNode* list2)
    {
         ListNode* dummyNode = new ListNode(-1);
         ListNode* temp = dummyNode;

        while (list1 != nullptr && list2 != nullptr) {
           
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
           
            temp = temp->next;
        }

       
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        return dummyNode->next;
    }
    

    
    ListNode* sortList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle=findmiddle(head);
        ListNode* lefthead=head;
        ListNode* righthead=middle->next;
        middle->next=NULL;

        lefthead=sortList(lefthead);
        righthead=sortList(righthead);

        return mergelist(lefthead,righthead);

        
    }
};
