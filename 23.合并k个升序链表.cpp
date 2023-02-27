/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
    
    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if(l > r){
            return nullptr;
        }
        if(l == r){
            return lists[l];
        }
        if(l + 1 == r){
            return mergerTwoLists(lists[l], lists[r]);
        }
        int m = l + (r - l) / 2;
        ListNode* l1 = merge(lists, l, m);
        ListNode* l2 = merge(lists, m + 1, r);
        return mergerTwoLists(l1, l2);
    }
    
    ListNode* mergerTwoLists(ListNode* l1, ListNode* l2){
        ListNode d(0);
        ListNode* tmp = &d;
        while(l1 && l2){
            // if(l1 -> val < l2 -> val){
            //     tmp -> next = l1;
            //     l1 = l1 -> next;
            //     tmp = tmp -> next;
            // }
            // else{
            //     tmp -> next = l2;
            //     l2 = l2 -> next;
            //     tmp = tmp -> next;
            // }
            if(l1 -> val > l2 -> val){
                swap(l1,l2);
            }
            tmp -> next = l1;
            l1 = l1 -> next;
            tmp = tmp -> next;
        }
        if(l1){
            tmp -> next = l1;
        }
        if(l2){
            tmp -> next = l2; 
        }
        return d.next;
    }
};
// @lc code=end

