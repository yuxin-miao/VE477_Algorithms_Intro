/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        while (currNode != nullptr) {
            head = currNode->next;
            currNode->next= prevNode;
            prevNode = currNode;
            currNode = head;
        }
        return prevNode;
    }
};
/* int main() {

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
    printListNode(sol.reverseList(initial->next));
} */
// @lc code=end

