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


// Driver Code. 
int main()
{
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
    }

    return 0;
} 