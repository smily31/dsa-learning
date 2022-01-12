// We have to print the intersection of two sorted array

// Approach -> use merge function of merge sort technique

#include <bits/stdc++.h>
using namespace std;

void intersection(int arr[], int n, int brr[], int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            i++;
            continue;
        }

        if (arr[i] < brr[j])
        {
            i++;
        }
        else if (arr[i] == brr[j])
        {
            cout << arr[i] << " ";
            i++;
            j++;
        }
        else if (arr[i] > brr[j])
        {
            j++;
        }
    }
}

int main()
{
    int arr[] = {2, 20, 20, 40, 60};
    int brr[] = {10, 20, 20, 20};
    int n = 5, m = 4;
    cout << "r u listrening to me \n";
    intersection(arr, n, brr, m);
    return 0;
}