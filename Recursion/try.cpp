#include <bits/stdc++.h>
using namespace std;

// Print subsquence whose sum is divisible by k

int subsquence(int arr[], int n, int i, int p, int k)
{
    if (i == n)
    {
        if (p < k )
        {
            return 1;
        }
        return 0;
    }

    p *= arr[i];
    int l = subsquence(arr, n, i + 1, p, k);

    p /= arr[i];
    int r = subsquence(arr, n, i + 1, p, k);

    return (l+r);
}

// main function
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k = 2;
    int p=1;
    cout<< subsquence(arr, n, 0, p, k);
    return 0;
}