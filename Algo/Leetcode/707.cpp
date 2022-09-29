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
void printListNode(ListNode* head) {
    cout << "printListNode ";
   while (head != nullptr)  {
        cout << head->val << " ";
        head = head->next; 
    }
    cout << endl;
} */
class MyLinkedList {
    ListNode* dummyFirst;
public:
    MyLinkedList() {
        dummyFirst = new ListNode();
    }
    
    int get(int index) {
        ListNode* currNode = dummyFirst->next;
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
        newFirst->next = dummyFirst->next;
        dummyFirst->next = newFirst;
    }
    
    void addAtTail(int val) {
        ListNode* currNode = dummyFirst->next;
        ListNode* prevNode = dummyFirst;
        ListNode* lastNode = new ListNode(val);
        while (currNode != nullptr)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        prevNode->next = lastNode;
        
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        ListNode* currNode = dummyFirst->next;
        ListNode* prevNode = dummyFirst;
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

        ListNode* currNode = dummyFirst->next;
        ListNode* prevNode = dummyFirst;

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
    ListNode* getFirstNode() {
        return dummyFirst->next;
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
/* enum class OperationType{
    addAtHead, addAtTail, addAtIndex, get, deleteAtIndex
};
int main() {
    MyLinkedList* obj = new MyLinkedList();
    int operationNum;
    cin >> operationNum;
    for (int i = 0; i < operationNum; i++)
    {
        OperationType type;
        
        int typeNum, num1, num2;
        cin >> typeNum;
        switch (typeNum)
        {
        case 0:
            cin >> num1;
            obj->addAtHead(num1);
            break;
        case 1:
            cin >> num1;
            obj->addAtTail(num1);
            break;
        case 2:
            cin >> num1 >> num2;
            obj->addAtIndex(num1, num2);
            break;
        case 3: 
            cin >> num1;
            cout << "print Get "<< obj->get(num1) << endl;
            break;
        case 4:
            cin >> num1;
            obj->deleteAtIndex(num1);
            break;
        default:
            break;
        }
        printListNode(obj->getFirstNode());
    }
    
} */
// @lc code=end

