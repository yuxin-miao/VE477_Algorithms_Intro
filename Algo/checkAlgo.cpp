#include <string>
#include <iostream>
#include <sstream>

using namespace std;


struct ListNode {
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void insertionSortArray(int arr[], int size);
void insertionSort(int arr[], int size);
void printLinkedList(ListNode* node) {
    while (node)
	{
		cout << node->val << " ";
		node = node->next;
	}
	
}



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
				cout << "currNode "<< currNode->val << endl;
                prevNode->next = currNode;
                prevNode = currNode;
                currNode = currNode->next;
				prevNode->next = nullptr;
            }
            
        }
        return firstNode->next;
    }
	void testInsertionSortList(int argc, char const *argv[]){
		ListNode* prevNode = new ListNode((int)argv[1]);
		ListNode* head = prevNode;
			for (int i=2; i<argc; i++) {
				ListNode* node = new ListNode((int)argv[i]);
				node->next = prevNode;
				prevNode = node;
			}
		
	}
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
    ListNode* deleteDuplicates1(ListNode* head) {
        if (head==nullptr || head->next == nullptr) return head;
        ListNode* firstNode = new ListNode(0);
        ListNode* prevNode = firstNode;
        ListNode* currNode = head;
        while(currNode) {
            while(currNode->next != nullptr && currNode->val == currNode->next->val) {
                currNode = currNode->next;
            }
            prevNode->next = currNode;
            prevNode = currNode;
            currNode = currNode->next;
            prevNode->next = nullptr;
        }
		return firstNode->next;
	}
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

void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void insertionSortArray(int arr[], int size) {
	printArr(arr, size);
	int tempNum;
	for (int i = 1; i < size; i++) {
		tempNum = arr[i];
		for (int j = i; j > 0; j--) {
			if (arr[j-1] > tempNum) {
				arr[j] = arr[j-1];
				arr[j-1] = tempNum;
			}
			else {
				arr[j] = tempNum;
				break;
			}
		}
	}
	printArr(arr, size);

}
void insertionSort(int arr[], int size) {
		printArr(arr, size);

	for (int i = 1; i < size; i++) {
		int num = arr[i];
		int j = i - 1;
		while (arr[j] > num && j >= 0) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = num;
	}
		printArr(arr, size);

}


int main() {
    ListNode* head = new ListNode(1);
	Solution sol;
    ListNode* prevNode = head;
	int arr[] = {1,4,3,2,5,2};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		ListNode* node = new ListNode(arr[i]);
		prevNode->next = node;
		prevNode = node;
	}
	printLinkedList(head);
	head = sol.partition(head, 3);
	printLinkedList(head);
	

}