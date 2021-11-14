// Given an array
// Find the largest sum of k size subarray

#include <bits/stdc++.h>
using namespace std;

// Naive approach


// sliding window approach
int best(int arr[], int n, int k)
{
    int i = 0, j = 0;      // start and end of window
    int sum = 0;           // store sum of subarray
    int largest = INT_MIN; // to store max sum of subarray
    while (j < n)
    {
        sum += arr[j];
        if (j - i + 1 < k) // condition to find size of window and while in process calculating the sum
        {
            j++;
        }
        else
        if (j - i + 1 == k)
        {
            largest = max(largest, sum);
            // logic to slide window with same size 
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return largest;
}

int main()
{
    int arr[] = {2,5,1,7,4};
    int n = 5;
    int k = 3;
    cout<<"The largest sum of subarray of size "<<k<<" is ";
    cout<<best(arr,n,k);
    return 0;
}