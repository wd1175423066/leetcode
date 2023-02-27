/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        int cnt = 1;
        ListNode* head_tmp = head;
        while(head -> next){
            ++cnt;
            head = head -> next;
        }
        head -> next = head_tmp;
        k %= cnt;
        for(int i = 0; i < cnt - k - 1; ++i){
            head_tmp = head_tmp -> next;
        }
        ListNode* res = head_tmp -> next;
        head_tmp -> next = nullptr;
        return res;

    }
};
// @lc code=end

