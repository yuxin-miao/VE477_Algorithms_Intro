/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
#include <iostream>
using namespace std;
/* struct ListNode
{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){};
    ListNode(int val): val(val), next(nullptr){};
};
     */
class MyLinkedList {
    ListNode* first;
public:
    MyLinkedList() {
        first = new ListNode();
    }
    
    int get(int index) {
        ListNode* currNode = first;
        int currIdx = 0;
        while (currNode != nullptr) {
            if (currIdx == index) return currNode->val;
            currIdx++;
            currNode = currNode->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode* newFirst = new ListNode(val);
        newFirst->next = first;
        first = newFirst;
    }
    
    void addAtTail(int val) {
        ListNode* currNode = first;
        ListNode* lastNode = new ListNode(val);
        while (currNode->next != nullptr)
        {
            currNode = currNode->next;
        }
        currNode->next = lastNode;
        
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        ListNode* currNode = first;
        ListNode* prevNode = first;
        ListNode* newNode = new ListNode(val);
        int currIdx = 0;
        while (currNode != nullptr) {
            if (currIdx == index) {
                newNode->next = currNode;
                prevNode->next = newNode;
                return;
            };
            currIdx++;
            prevNode = currNode;
            currNode = currNode->next;
        }
        if (currIdx == index) addAtTail(val);
        return;
    }
    
    void deleteAtIndex(int index) {

        ListNode* currNode = first;
        ListNode* prevNode = first;

        int currIdx = 0;
        while (currNode != nullptr) {
            if (currIdx == index) {
                prevNode->next = currNode->next;
                delete currNode;
                return;
            };
            currIdx++;
            prevNode = currNode;
            currNode = currNode->next;
        }

        return;    
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
/* int main() {
    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(index);
    obj->addAtHead(val);
    obj->addAtTail(val);
    obj->addAtIndex(index,val);
    obj->deleteAtIndex(index);
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

