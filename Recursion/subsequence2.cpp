#include <bits/stdc++.h>
using namespace std;

// Print subsquence whose sum is divisible by k

void subsquence(int arr[], int n, int i, vector<int> &v, int sum, int k)
{
    if (i == n)
    {
        if (sum % k == 0)
        {
            for (auto i : v)
                cout << i << " ";
            cout << endl;
        }
        return;
    }

    v.push_back(arr[i]);
    sum += arr[i];
    subsquence(arr, n, i + 1, v, sum, k);
    v.pop_back();
    sum -= arr[i];
    subsquence(arr, n, i + 1, v, sum, k);
}

// main function
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k = 3;
    int sum = 0;
    vector<int> v;
    subsquence(arr, n, 0, v, sum, k);
    return 0;
}