// 3.5 稳定排序 p48

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

struct Card
{
    char type;
    int num;
};
void printCard(Card arr[], int size);
void bubbleSort(Card arr[], int size);
void selectionSort(Card arr[], int size);

int main() {
    int cardNum;
    cin >> cardNum;
    Card C1[100], C2[100];
    for (int i = 0; i < cardNum; i++) {
        cin >> C1[i].type >> C1[i].num;
    }
    for (int i = 0; i < cardNum; i++)
    {
        C2[i] = C1[i];
    }
    bubbleSort(C1, cardNum);
    selectionSort(C2, cardNum);
    printCard(C1, cardNum);
    printCard(C2, cardNum);
}

void printCard(Card arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i].type << arr[i].num << ' ';
    }
}

void bubbleSort(Card arr[], int size) {
    // bubble sort the part that has been sorted (0-i), do not need to be compared 
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j >= i+1; j--) {
            if (arr[j].num < arr[j-1].num) {
                Card temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}
void selectionSort(Card arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        int minIdx = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j].num < arr[minIdx].num) {
                minIdx = j;
            }
        }
        Card temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
    
}