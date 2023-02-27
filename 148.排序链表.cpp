/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode* tail){
        if(!head){
            return head;
        }
        if(head -> next == tail){ 
            head -> next = nullptr; //trick
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != tail){
            slow = slow -> next;
            fast = fast -> next;
            if(fast != tail){
                fast = fast -> next;
            }
        }
        return merge(sortList(head, slow), sortList(slow, tail));
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode d(0);
        ListNode* tail = &d;
        while(l1 && l2){
            if(l1 -> val > l2 -> val){
                swap(l1, l2);
            }
            tail -> next = l1;
            l1 = l1 -> next;
            tail = tail -> next;
        }
        tail -> next = l1 ? l1 : l2;
        return d.next;
    }
};
// @lc code=end

