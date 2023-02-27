/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode d(INT_MIN);
        ListNode* curr = &d;
        while(head){
            ListNode* tmp = head;
            ListNode* prev = nullptr;
            head = head -> next;
            
            while(curr && tmp -> val > curr -> val){
                prev = curr;
                curr = curr -> next;
            }

            tmp -> next = prev -> next;
            prev -> next = tmp;

            curr = &d;
            prev = nullptr;
        }
        return d.next;
    }
};
// @lc code=end

