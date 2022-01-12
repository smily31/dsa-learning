// Quick sort algorithm using lomuto partition
// not stable 

#include <bits/stdc++.h>
using namespace std;

int lomuto(int arr[], int l, int h)
{
    int p = arr[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
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
void quickSortLomuto(int arr[], int l, int h)
{
    if (l < h) // mean if only greater than 1 element is there
    {
        int p = lomuto(arr, l, h);
        quickSortLomuto(arr, l, p - 1);
        quickSortLomuto(arr, p + 1, h);
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
    quickSortLomuto(arr, 0, n - 1);
    display(arr, 0, n - 1);
    return 0;
}