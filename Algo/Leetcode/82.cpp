/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

// @lc code=start

// Definition for singly-linked list.

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        int valStore = head->val == head->next->val ? head->val : head->val - 1;
        ListNode* firstNode = new ListNode(0);
        
        ListNode* currNode = head;
        ListNode* prevNode = firstNode;
        
        while (currNode)
        {
            if (currNode->next!=nullptr && currNode->val == currNode->next->val) valStore = currNode->val;
            while (currNode!=nullptr && currNode -> val == valStore) {
                currNode = currNode ->next;
            }
            if (currNode == nullptr)
            {
                break;
            }
            
            if (currNode->next && currNode->val == currNode->next->val) {
                valStore = currNode->val;
            } else {
                prevNode->next = currNode;
                prevNode = currNode;
                currNode = currNode->next;
                prevNode->next = nullptr;
            }
            
        }
        return firstNode->next;
    }
};

// @lc code=end

