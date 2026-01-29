class Solution {
  public:
    int lengthOfLoop(Node *head)
    {
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return findlength(slow,fast);     
        }
        return 0;
    }
    
    int findlength(Node* slow ,Node* fast)  
    {
        int count=1 ;
        Node* temp=fast->next;
        while(temp!=slow)
        {
            count++;
            temp=temp->next;
        }
        return count;
        
    }
};
