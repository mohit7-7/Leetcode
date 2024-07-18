/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void addtotail(struct ListNode **head, struct ListNode **tail, int data){
    struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = data;
    temp->next= NULL;
    if(!(*head)){
        *head= temp;
        *tail= temp;
        return;
    }
    (*tail)->next= temp;
    (*tail)= temp;  
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry=0;
    struct ListNode* head= NULL;
    struct ListNode* tail= NULL;
    while(l1 || l2 || carry){
        int val1=0;
        if(l1)
            val1=l1->val;
        int val2=0;
        if(l2)
            val2=l2->val;
        int sum= val1+val2+carry;
        int digit= sum%10;
        carry= sum/10;
        addtotail(&head,&tail,digit);
        if(l1)
            l1=l1->next;
        if(l2)
            l2=l2->next;
    }
    return head;
}