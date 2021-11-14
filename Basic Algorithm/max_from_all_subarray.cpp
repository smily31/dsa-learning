// Find the maximum number from all subarray of size k
// Video reference to understand the code :-> https://www.youtube.com/watch?v=xFJXtB5vSmM&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=6

#include <bits/stdc++.h>
using namespace std;

vector<int> best(vector<int> v, int k)
{
    int i = 0, j = 0;
    vector<int> ans;
    list<int> l;

    if (k > v.size())
    {
        ans.push_back(*max_element(v.begin(), v.end()));
        return ans;
    }
    // logic begins
    while (j < v.size())
    {
        if (l.size() == 0)
            l.push_back(v[j]);
        else
        {
            while (l.back() < v[j] && !l.empty())
                l.pop_back();
            l.push_back(v[j]);
        }
        // reaching to the size of k and finding ans
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            ans.push_back(l.front()); // answer
            if (v[i] == l.front())
                l.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}

// main function
int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> v = best(arr,k);
    for(const auto &it:v)
        cout<<it<<" ";
    return 0;
}