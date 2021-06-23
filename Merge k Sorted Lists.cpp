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
    ListNode* mergeKLists(vector<ListNode*> &l)
    {
        ListNode *res = new ListNode(0), *temp = res;

        checkpoint:

            int min_ele = INT_MAX;

            for(int i = 0; i < l.size(); i++)
                if(l[i] != NULL && l[i]->val < min_ele)
                    min_ele = l[i]->val;

            for(int i = 0; i < l.size(); i++)
                if(l[i] != NULL && l[i]->val == min_ele)
                {
                    temp->next = new ListNode(min_ele);
                    temp = temp->next;
                    l[i] = l[i]->next;
                }

            for(int i = 0; i < l.size(); i++)
                if(l[i] != NULL)
                    goto checkpoint;

        return res->next;
    }
};
