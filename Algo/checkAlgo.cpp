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

int main(int argc, char const *argv[])
{
	
	int foo [5] = { 16, 2, 77, 40, 12071 };	
	insertionSort(foo, 5);
	return 0;
}

class Solution {
public:
	void testInsertionSortList(int argc, char const *argv[]){
		ListNode* prevNode = new ListNode((int)argv[1]);
		ListNode* head = prevNode;
			for (int i=2; i<argc; i++) {
				ListNode* node = new ListNode((int)argv[i]);
				node->next = prevNode;
				prevNode = node;
			}
		
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
void checkARGVBtye(int argc, char const *argv[]) {
		std::cout << "executable= " << argv[0] << std::endl;

	for (int i=1; i<argc; i++) {
		std::string s(argv[i]); //put char array into a string

		std::cout << "arg["<<i<<"]="<<s<<std::endl;

		for (int j=0; j<6; j+=2) {

			std::string byteString = s.substr(j, 2);

			char byte = (char) strtol(byteString.c_str(), NULL, 16);

			std::cout << "byteString= "<<byteString << " as integer= "<<(int)byte<<std::endl;
		}
	}
}
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
