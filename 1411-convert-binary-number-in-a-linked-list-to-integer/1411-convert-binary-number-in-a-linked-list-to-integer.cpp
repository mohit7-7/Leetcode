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

    int recursion(ListNode*head, int&ans){
        if(head==NULL) {
            return 0;
        }
        int power= recursion(head->next,ans);
        ans += (head->val<<power);
        return power+=1;
    }
    int getDecimalValue(ListNode* head) {
        int ans=0;
        recursion(head, ans);
        return ans;
    }
};