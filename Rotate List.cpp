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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == NULL)
            return NULL;
        if(head->next == NULL || k == 0)
            return head;

        int n = 1;

        ListNode *temp = head;

        for( ; temp->next != NULL; n++)
            temp = temp->next;

        ListNode *lastNode = temp, *prev = head;

        k %= n;
        if(k == 0)
            return head;

        for(int i=0; i<n-k-1; i++)
            prev = prev->next;

        temp = prev->next;
        prev->next = NULL;
        lastNode->next = head;
        head = temp;

        return head;
    }
};
