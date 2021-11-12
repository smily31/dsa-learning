#include <bits/stdc++.h>
using namespace std;

// SELECTION SORT ALGORITHM -> Does less memory writes compared to QS, MS, IS, etc.
// But Cycle sort is optimal in terms of memory writes

// It is Basic Idea for HEAP SORT
// Not Stable
// In Place

// TC in all case - O(n^2)
// SC - O(1)

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j; // finding the index of smallest in the given array
        }
        swap(arr[min_index], arr[i]); // swapping it with its appropiate index's element
    }
}

// Displaying the array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// main function
int main()
{
    int arr[10] = {8, 7, 5, 9, 0, 1, 8, 6, 6, 3};
    selectionSort(arr, 10);
    print(arr, 10);
    return 0;
}