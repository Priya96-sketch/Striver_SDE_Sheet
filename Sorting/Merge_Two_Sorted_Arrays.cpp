//1st Approach ->By using a third array, which will cost Extra Space
// Time Complexity for the first approach is -> O(log n)+ O(N) + O(N) . Also here the approach is being implemented for unsorted array. Hence to sort the array time Complexity is 
// O(log n).

//2nd Approach -> Insertion Sort kinda algorithm, where no extra space will be occupied.
//Time Complexity for the 2nd Approach -> O(n1*m1). n1 -> for linear traversal through the first array. m1 -> for rearranging the elements in the array.
// This is GAP METHOD.
// In this/ method -> First add the number of elements of the two arrays and then divided by do. Repeat the process unill it becomes 1.
//For example if 1st = 5 in size & 2nd = 3 in size.
// Gap ->8/2 = 4
// Gap -> 4/2=2
// Gap -> 2/2 =1

#include <iostream>
#include <algorithm>
using namespace std;
 
// Utility function to print contents of an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
// Function to in-place merge two sorted arrays X[] and Y[]
// invariant: `X[]` and `Y[]` are sorted at any point
void merge(int X[], int Y[], int m, int n)
{
    // Consider each element `X[i]` of array `X` and ignore the element if it is
    // already in the correct order; otherwise, swap it with the next smaller
    // element, which happens to be the first element of `Y`.
    for (int i = 0; i < m; i++)
    {
        // compare the current element of `X[]` with the first element of `Y[]`
        if (X[i] > Y[0])
        {
            swap(X[i], Y[0]);
            int first = Y[0];
 
            // move `Y[0]` to its correct position to maintain the sorted
            // order of `Y[]`. Note: `Y[1…n-1]` is already sorted
            int k;
            for (k = 1; k < n && Y[k] < first; k++) {
                Y[k - 1] = Y[k];
            }
 
            Y[k - 1] = first;
        }
    }
}
 
int main()
{
    int X[] = { 1, 4, 7, 8, 10 };
    int Y[] = { 2, 3, 9 };
 
    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);
 
    merge(X, Y, m, n);
 
    cout << "X: "; printArray(X, m);
    cout << "Y: "; printArray(Y, n);
 
    return 0;
}
