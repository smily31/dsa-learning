// Quick sort algorithm using hoare's partition method
// not stable
// but 3 times faster than lomuto on average

#include <bits/stdc++.h>
using namespace std;

int hoare(int arr[], int l, int h)
{
    int p = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < p);
        do
        {
            j--;
        } while (arr[j] > p);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

void quickSortHoare(int arr[], int l, int h)
{
    if (l < h) // base case: array have atleast 2 elements
    {
        int p = hoare(arr, l, h);
        quickSortHoare(arr, l, p); // since the pivot is not at its correct place
        quickSortHoare(arr, p + 1, h);
    }
}

void display(int arr[], int l, int h)
{
    cout << '\n';
    for (int i = l; i <= h; i++)
        cout << arr[i] << " -> ";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    cout << "enter array element \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    display(arr, 0, n - 1);
    quickSortHoare(arr, 0, n - 1);
    display(arr, 0, n - 1);
    return 0;
}