/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* smaller = new ListNode(0);
        ListNode* begin = smaller;
        ListNode* larger = new ListNode(0);
        ListNode* secondBegin = larger;
        ListNode* currNode = head;
        while (currNode) {
            if (currNode->val < x) {
                smaller->next = currNode;
                smaller = currNode;
                currNode = currNode->next;
                smaller->next = nullptr;
            }
            else 
            {
                larger->next = currNode;
                larger = currNode;
                currNode = currNode->next;
                larger->next = nullptr;
            }
        }
        smaller->next = secondBegin->next;
        return begin->next;
    }
};
// @lc code=end

