#include <bits/stdc++.h>
using namespace std;

// MERGE SORT ALGORITHM
// Uses Divide and Conquer Algo  -> (divide,conquer,merge)
// Stable
// Not In Place
// Well suited for Linked List . Works in O(1) A.S.
// Used in External Sorting
// In general for arrays, Quick Sort outperforms in

// TC - O(nlogn) - for best-avg-worst case
// AS - O(n)

// function to merge two sorted array
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[n1 + i];

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

// main logic of mergesort
void mergeSort(int arr[], int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    else
        return;
}

// main function
int main()
{
    int arr[] = {5,4,3,2,1};
    int n = 5;
    // calling sort function
    mergeSort(arr, 0, n - 1);
    // Printing array after sorting
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}