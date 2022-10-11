#include <vector>
#include <iostream>

using namespace std;
int main() {
    int num;
    cin >> num;
    vector<int> arr;
    int val;
    for (int i = 0; i < num; i++)
    {
        cin >> val;
        arr.push_back(val);
    }
    
    int maxSum = 0;
    int count = 0;
    for(int i = num - 1; i > 0; i--) {
        if(arr[i] > arr[i-1]) {
            arr[i-1] = arr[i];
            count++;
        }
        maxSum += arr[i];
    }
    maxSum += arr[0];
    cout << maxSum << " " << count << endl;
}