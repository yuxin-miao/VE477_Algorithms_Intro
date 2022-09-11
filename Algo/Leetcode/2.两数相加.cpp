/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int count = 0;
        ListNode* head = new ListNode(0);
        ListNode* prevNode = head;

        while (l1 != nullptr || l2 != nullptr || count != 0)
        {
            int l1val = l1 != nullptr? l1->val : 0;
            int l2val = l2 != nullptr? l2->val : 0;
            int num = l1val + l2val + count;
            count = num / 10;

            ListNode* node = new ListNode(num % 10);
            prevNode->next = node;
            prevNode = node;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return head->next;
    }
};

// @lc code=end

