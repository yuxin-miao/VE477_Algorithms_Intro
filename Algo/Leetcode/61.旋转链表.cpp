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
        int ptr1 = 0;
        int ptr2 = 0;
        if (head == nullptr || k == 0 || head->next == nullptr) return head;
        ListNode* newFirst = head;
        ListNode* oldLast = head;
        while (oldLast->next)
        {
            oldLast = oldLast->next;
            ptr2++;
        }
        int len = ptr2;
        k = k % (ptr2 + 1);
        if (k == 0) return head;
        ptr2 = 0;
        while (ptr2 != len) {
            ptr2++;
            if (ptr2 - ptr1 > k ) {
                ptr1++;
                newFirst = newFirst->next;
            }
        }
        ListNode* newLast = newFirst;
        newFirst = newFirst->next;
        newLast->next = nullptr;
        oldLast->next = head;
        return newFirst;


    }
};
// @lc code=end

