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
        if (head==nullptr || head->next == nullptr) return head;
        ListNode* firstNode = new ListNode(0);
        ListNode* prevNode = firstNode;
        ListNode* currNode = head;
        while(currNode) {
            while(currNode->next != nullptr && currNode->val ==currNode->next->val) {
                currNode = currNode->next;
            }
            prevNode->next = currNode;
            prevNode = currNode;
            currNode = currNode->next;
            prevNode->next = nullptr;
        }
        head = firstNode->next;
        delete firstNode;
        return head;
    }
};
// @lc code=end

