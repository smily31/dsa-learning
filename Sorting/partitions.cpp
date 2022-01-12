// Partition the array according to given pivot
// It means the array gets rearranged in such a way that all number smaller than or equal to is comes before the pivot element
// and greater elements come after pivot
#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int l, int h)
{
    for (int i = l; i <= h; i++)
        cout << arr[i] << " ";
}

// Naive approach
// TC-O(n)
// ASC-O(n)
void naivePartition(int arr[], int l, int h, int p)
{
    int temp[h - l + 1];
    int j = 0;
    for (int i = l; i <= h; i++)
    {
        if (arr[i] <= arr[p])
            temp[j] = arr[i];
        j++;
    }
    for (int i = l; i <= h; i++)
    {
        if (arr[i] > arr[p])
            temp[j] = arr[i];
        j++;
    }
    for (int i = l; i <= h; i++)
        arr[i] = temp[i - l];
    print(arr, l, h);
}

// Lomuto Partition -> Pivot is assumed to be last element of array
// The function returns the position of pivot after partition
// It is not stable
// TC - O(n)
// AS - O(1)
int lomuto(int arr[], int l, int h)
{
    int p = arr[h];
    int i = l - 1; // elements before i are numbers less than or equal to pivot
    // from i+1 to j numbers greater than pivot
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < p)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

// Hoare's partition :-> pivot is assumed to be first element
// do less comparison than lomuto but pivot is not at right position
// It is not stable
// TC - O(n)
// AS - O(1)
int hoare(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;  // elements before j are <= to pivot and elements after j are >= pivot
        swap(arr[i], arr[j]);
    }
}

int main()
{
    int arr[] = {5, 13, 6, 9, 12, 11, 8};
    int l = 0, h = 6, p = 6;
    print(arr, l, h);
    naivePartition(arr, l, h, p);

    return 0;
}