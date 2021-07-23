#include<bits/stdc++.h>
using namespace std;

// Count the subsequence whose sum is divisible by k
// learn the concept which is used in count through recursion

int subsquence(int arr[], int n, int i, vector<int> &v, int sum, int k)
{
    if (i == n)
    {
        if (sum % k == 0)
        {
            return 1;
        }
        else 
        return 0;
    }

    v.push_back(arr[i]);
    sum += arr[i];
    int l = subsquence(arr, n, i + 1, v, sum, k);
    v.pop_back();
    sum -= arr[i];
    int r = subsquence(arr, n, i + 1, v, sum, k);

    return l+r;
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
    cout<<"Count of subsequence sum divisible by k is "<<subsquence(arr, n, 0, v, sum, k)-1;
    return 0;
}