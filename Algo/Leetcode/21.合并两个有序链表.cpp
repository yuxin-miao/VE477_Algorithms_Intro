/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* preNode = head;
        while (list1 != nullptr || list2 != nullptr) {
            int val1 = list1 != nullptr ? list1->val : 101;
            int val2 = list2 != nullptr ? list2->val : 101;
            if (val1 > val2) {
                preNode->next = list2;
                preNode = list2;
                list2 = list2->next;
            } else {
                preNode->next = list1;
                preNode = list1;
                list1 = list1->next;
            }
        }
        return head->next;
    }
};
// @lc code=end

