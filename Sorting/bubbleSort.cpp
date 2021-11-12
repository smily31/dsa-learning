#include <bits/stdc++.h>
using namespace std;

// BUBBLE SORT ALGORITHM (uses comparison to sort)
// It is Stable sorting method
// In Place

// Swapping function
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

// TC- avg and worst case is O(n^2)
// AS- O(1)
void bubble(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // for Ascending order
                // if(arr[i] < arr[j])       // for Descending order
                swap(arr[j], arr[j + 1]);
        }
    }
}

// TC- best case (is when the array is already sorted or gets sorted in the middle of the process)-O(n)
// AS- O(1)
void bubbleOptimised(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            // if(arr[i] > arr[j])       // for Ascending order
            if (arr[j] < arr[j + 1]) // for Descending order
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }    
        }
        if (!isSwapped)
        {
            cout<<"optimised hai \n";
            break;
        }
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
    // int arr[10] = {8, 7, 5, 9, 0, 1, 8, 6, 6, 3};
    // bubble(arr, 10);
    // print(arr, 10);
    int arr[5] = {8,7,6,5,4};
    bubbleOptimised(arr, 5);
    print(arr, 5);
    return 0;
}
