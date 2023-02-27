/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;

        ListNode* pre = head;

        ListNode* res = head;
        head = head -> next;
        while(head){
            if(head -> val == pre -> val){
                pre -> next = head -> next;
            }
            else{
                pre = head;
            }
            head = head -> next;
        }
        return res;
    }
};
// @lc code=end

