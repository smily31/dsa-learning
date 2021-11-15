// Find the size of largest subarray whose sum is equal to given value k
// Video reference to understand code :- https://www.youtube.com/watch?v=cyu_nuW5utA&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=7
#include <bits/stdc++.h>
using namespace std;

// sliding window technique
// variable sized
// this technique will only work with positive values
int best(vector<int> v, int k)
{
    int i = 0, j = 0;
    int ans = INT_MIN;
    long long sum = 0;
    // logic begins
    while (j < v.size())
    {
        sum += v[j];
        if (sum < k)
            j++;
        else if (sum == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {
            while (sum > k)
            {
                sum -= v[i];
                i++;
            }
            if (sum == k)
                ans = max(ans, j - i + 1);
            j++;
        }
    }
    return ans;
}

// main function
int main()
{
    // vector<int> v = {4, 1, 1, 1, 2, 3, 5};
    vector<int> v = {1, 1, 1, 2};
    int k = 2;
    cout << "Largest subarray of sum of " << k << " is " << best(v, k);
    return 0;
}