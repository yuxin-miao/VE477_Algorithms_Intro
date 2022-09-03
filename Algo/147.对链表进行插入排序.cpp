/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 */

// @lc code=start

// Definition for singly-linked list.
/* struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; */

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* initHead = head;
        head = head->next;
        while (head)
        {
            ListNode* nextHead = head->next;
            ListNode* prevHead = initHead;
            while (prevHead->next)
            {
                if (prevHead->val <= head->val) {
                    if (prevHead->next && prevHead->next->val > head->val) {
                        head->next = prevHead->next;
                        prevHead->next = head;
                        prevHead = head->next;
                    }
                } else {
                    prevHead->next = nextHead;
                    head->next = prevHead;
                    initHead = head;
                    break;
                }
                if (prevHead->next == head) {
                    prevHead->next = nextHead;
                    break;
                }
                
            }
            head = nextHead;
        }
        return initHead;
    }
};
// @lc code=end

