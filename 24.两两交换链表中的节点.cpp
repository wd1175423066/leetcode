/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next){
            return head;
        }
        ListNode d(0);
        d.next = head;
        head = &d;
        while(head && head -> next && head -> next -> next){
            ListNode* n1 = head -> next;
            ListNode* n2 = n1 -> next;

            n1 -> next = n2 -> next;
            n2 -> next = n1;
            head -> next = n2;

            head = n1;
        }
        return d.next;
    }
};
// @lc code=end

