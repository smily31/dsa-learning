#include <bits/stdc++.h>
using namespace std;

// INSERTION SORT ALGORITHM
// In Place
// Stable
// Used in practice for small size arrays in Hybrid Sorting Technique (Tim Sort, Intro Sort)

// TC - O(n^2)  in avg and worst case
// TC - O(n) in best case(when your array is already sorted)
// SC - O(1)

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1; // this becomes the end point of sorted array section
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // inserting the key element from unsorted array section to sorted array section
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
    insertionSort(arr, 10);
    print(arr, 10);
    return 0;
}