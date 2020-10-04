#include <iostream>
#include <vector>
#include <cmath>
// CPP program to find all subsets by backtracking.
using namespace std;

// In the array A at every step we have two 
// choices for each element either  we can 
// ignore the element or we can include the 
// element in our subset 
void subsetsUtil(vector<int>& A, vector<vector<int> >& res,
                 vector<int>& subset, int index)
{
    res.push_back(subset);
    for (int i = index; i < A.size(); i++) {

        // include the A[i] in subset. 
        subset.push_back(A[i]);

        // move onto the next element. 
        subsetsUtil(A, res, subset, i + 1);

        // exclude the A[i] from subset and triggers 
        // backtracking. 
        subset.pop_back();
    }

    return;
}

// below function returns the subsets of vector A. 
vector<vector<int> > subsets(vector<int>& A)
{
    vector<int> subset;
    vector<vector<int> > res;

    // keeps track of current element in vector A; 
    int index = 0;
    subsetsUtil(A, res, subset, index);

    return res;
}

class gfg
{

public:
    static void printPowerSet(char *set, int set_size)
    {
        /*set_size of power set of a set with set_size
        n is (2**n -1)*/
        unsigned int pow_set_size = pow(2, set_size);
        int counter, j;

        /*Run from counter 000..0 to 111..1*/
        for(counter = 0; counter < pow_set_size; counter++)
        {
            for(j = 0; j < set_size; j++)
            {
                /* Check if jth bit in the counter is set
                    If set then print jth element from set */
                cout <<"counter: " << counter << endl;
                auto x = j >> 1;
                cout << "1 << j: " <<  x << " " << j << endl;
                if(counter & (1 << j))
                    cout << set[j];
            }
            cout << endl;
        }
    }
};
// This function generates all n bit Gray codes and prints the
// generated codes
void generateGrayarr(int n)
{
    // base case
    if (n <= 0)
        return;

    // 'arr' will store all generated codes
    vector<string> arr;

    // start with one-bit pattern
    arr.push_back("0");
    arr.push_back("1");

// Every iteration of this loop generates 2*i codes from previously
// generated i codes.
    int i, j;
    for (i = 2; i < (1<<n); i = i<<1)
    {cout << "!!!" << endl;
    // Enter the prviously generated codes again in arr[] in reverse
    // order. Nor arr[] has double number of codes.
    for (j = i-1 ; j >= 0 ; j--)
    arr.push_back(arr[j]);

    // append 0 to the first half
    for (j = 0 ; j < i ; j++)
    arr[j] = "0" + arr[j];

    // append 1 to the second half
    for (j = i ; j < 2*i ; j++)
    arr[j] = "1" + arr[j];
    }

    // print contents of arr[]
    for (i = 0 ; i < arr.size() ; i++ )
    cout << arr[i] << endl;
}
// CPP program to generate all unique
// partitions of an integer
#include<iostream>
using namespace std;

// A utility function to print an array p[] of size 'n'
void printArray(int p[], int n)
{
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << endl;
}

void printAllUniqueParts(int n)
{
    int p[n]; // An array to store a partition
    int k = 0; // Index of last element in a partition
    p[k] = n; // Initialize first partition as number itself

    // This loop first prints current partition then generates next
    // partition. The loop stops when the current partition has all 1s
    while (true)
    {
        // print current partition
        printArray(p, k+1);

        // Generate next partition

        // Find the rightmost non-one value in p[]. Also, update the
        // rem_val so that we know how much value can be accommodated
        int rem_val = 0;
        while (k >= 0 && p[k] == 1)
        {
            rem_val += p[k];
            k--;
        }

        // if k < 0, all the values are 1 so there are no more partitions
        if (k < 0) return;

        // Decrease the p[k] found above and adjust the rem_val
        p[k]--;
        rem_val++;


        // If rem_val is more, then the sorted order is violated. Divide
        // rem_val in different values of size p[k] and copy these values at
        // different positions after p[k]
        while (rem_val > p[k])
        {
            p[k+1] = p[k];
            rem_val = rem_val - p[k];
            k++;
        }

        // Copy rem_val to next position and increment position
        p[k+1] = rem_val;
        k++;
    }
}




// Driver Code. 
int main()
{
    printAllUniqueParts(6);
    /*generateGrayarr(6);
    // find the subsets of below vector. 
    vector<int> array = { 1, 2, 3 };
    char set[] = {'a', 'b', 'c'};
    gfg g;
    g.printPowerSet(set,3);

    // res will store all subsets. 
    // O(2 ^ (number of elements inside array)) 
    // because at every step we have two choices 
    // either include or ignore. 
    vector<vector<int> > res = subsets(array);

    // Print result 
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }*/

    return 0;
} 