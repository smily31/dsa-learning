#include <bits/stdc++.h>
using namespace std;

// Binary Search - recursive method

// currently this is not working but concept is correct

bool binarysearch(int v[], int l, int u, int k)
{
    if (l <= u)
    {
        int mid = l + (u - l) / 2;
        if (v[mid] == k)
            return true;
        if (k < v[mid])
            binarysearch(v, l, mid - 1, k);
        else
            binarysearch(v, mid + 1, u, k);
    }
    else
        return false;
}

// main function
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "enter no to be searched " << endl;
    int k;
    cin >> k;
    cout << "No is present(true/false) : " <<binarysearch(arr, 0, n - 1, k);
    return 0;
}