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
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1){
            cur->next = l1;
        }
        else{
            cur->next = l2;
        }
        return dummy->next;
    }
    ListNode* mergeSort(vector<ListNode*>&lists, int l, int r){
        if(l>r)return nullptr;
        if(l==r)return lists[l];
        int mid = (l+r)>>1;
        ListNode* left = mergeSort(lists,l,mid);
        ListNode* right = mergeSort(lists,mid+1,r);
        return merge(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeSort(lists,0,lists.size()-1);
    }
};
