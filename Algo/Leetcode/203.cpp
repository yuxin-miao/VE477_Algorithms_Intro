/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
#include <iostream>
using namespace std;
/*  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printListNode(ListNode* head) {
   while (head != nullptr)  {
        cout << head->val << " ";
        head = head->next; 
   }
} */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prevNode = new ListNode(); 
        ListNode* returnNode = prevNode;
        while (head != nullptr)
        {
            if (head->val == val) {
                ListNode* currNode = head;
                head = head->next;
                delete currNode;
            } else {
                prevNode->next = head;
                prevNode = head;
                head = head->next;
                prevNode->next = nullptr;
            }
        }
        return returnNode->next;
    }
};
/* int main() {
    int deleteNum;
    cin >> deleteNum;
    int num;
    cin >> num;
    ListNode* head = new ListNode();
    ListNode* initial = head;
    for (int i = 0; i < num; i++)
    {
        int val;
        cin >> val;
        ListNode* curr = new ListNode(val);
        head->next = curr;
        head = head->next;
 
    }
    Solution sol;
    printListNode(sol.removeElements(initial->next, deleteNum));
} */
// @lc code=end

