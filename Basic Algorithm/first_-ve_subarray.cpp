// Given an array of integers
// print first negative number in each and every subarray of size k
// print zero if no negative number is present in that subarray

#include<bits/stdc++.h>
using namespace std;

// better solution
// sliding window approach

vector<long long> best(long long arr[], long long n, long long k)   // following code get accepted in gfg
{
    long long i=0,j=0;
    list<long long> l;
    vector< long long> v;
    while(j<n)
    {
        if(arr[j] < 0)
            l.push_back(arr[j]);
        if(j-i+1 < k)
        {
            j++;
        }
        else if(j-i+1 == k)
        {
            if(l.size() == 0)
                v.push_back(0);
            else
            {
                v.push_back(l.front());
                if(arr[i] == l.front())
                {
                    l.pop_front();
                }
            }
            i++;
            j++;
        }
    }
        return v;
}

int main()
{
    long long arr[] = {-8, 2, 3, -6, 10};
    long long n = 5, k = 2;
    vector<long long> v = best(arr, n, k);
    for(const auto &i:v)
        cout<<i<<" ";
    return 0;
}