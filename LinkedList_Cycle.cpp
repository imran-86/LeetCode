class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        map<ListNode*,int>m;
        if(temp==NULL){
            return false;
        }
        while(temp!=NULL){
         if(m[temp]){
            return true;
         }
         else{
            m[temp]=1;
            temp=temp->next;
         }
        } 
        return false;
    }
};