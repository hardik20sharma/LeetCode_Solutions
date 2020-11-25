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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<int> s1, s2;

        for(ListNode *temp = l1; temp != NULL; temp = temp->next)
            s1.push(temp->val);
        for(ListNode *temp = l2; temp != NULL; temp = temp->next)
            s2.push(temp->val);

        int carry = 0;
        ListNode *next = NULL;

        while(!s1.empty() || !s2.empty())
        {
            int temp = carry;
            
            if(!s1.empty())
                { temp += s1.top(); s1.pop(); }
            if(!s2.empty())
                { temp += s2.top(); s2.pop(); }
            
            carry = temp/10;
            temp %= 10;
            
            ListNode *curr = new ListNode(temp);
            curr->next = next;
            next = curr;
        }
        
        if(carry)
        {
            ListNode *curr = new ListNode(carry);
            curr->next = next;
            next = curr;
        }
        
        return next;
    }
};
