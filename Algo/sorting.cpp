
// Write in Ve281 

// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

// Inplace Implementation
void merge(int arr[], int start, int mid, int end);
void mergeSort(int arr[], int l, int r);

void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);

/* Driver program to test above functions */


int main()
{
    int arr[] = { 12, 11, 11, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);
    insertionSort(arr, arr_size);
    selectionSort(arr, arr_size);
    //printArray(arr, arr_size);
    return 0;
}

// C++ program in-place Merge Sort
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
// Inplace Implementation 
void merge(int arr[], int start, int mid, int end) 
{ 
    int start2 = mid + 1; 
  
    // If the direct merge is already sorted 
    if (arr[mid] <= arr[start2]) { 
        return; 
    } 
  
    // Two pointers to maintain start 
    // of both arrays to merge 
    while (start <= mid && start2 <= end) { 
  
        // If element 1 is in right place 
        if (arr[start] <= arr[start2]) { 
            start++; 
        } 
        else { 
            int value = arr[start2]; 
            int index = start2; 
  
            // Shift all the elements between element 1 
            // element 2, right by 1. 
            while (index != start) { 
                arr[index] = arr[index - 1]; 
                index--; 
            } 
            arr[start] = value; 
  
            // Update all the pointers 
            start++; 
            mid++; 
            start2++; 
        } 
    } 
} 
  
/* l is for left index and r is right index of the  
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
  
        // Same as (l + r) / 2, but avoids overflow 
        // for large l and r 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
}
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array
void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} */

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
