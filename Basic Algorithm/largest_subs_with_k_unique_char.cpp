// Find the size of largest substring with k unique characters
// Video reference to understand the code :-> https://www.youtube.com/watch?v=Lav6St0W_pQ&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=11

#include <bits/stdc++.h>
using namespace std;

// variable size sliding window technique solution
int best(string str, int k)
{
    int i = 0, j = 0;
    int ans = -1; // in case we don't get satisfied answer according to question we will by default return -1
    map<char, int> m;

    // logic begins
    while (j < str.size())
    {
        m[str[j]]++;

        if (m.size() < k)
            j++;
        else if (m.size() == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {
            while (m.size() > k)
            {
                m[str[i]]--;
                if (m[str[i]] == 0)
                    m.erase(str[i]);
                i++;
            }
            if (m.size() == k)
                ans = max(ans, j - i + 1);
            j++;
        }
    }
    return ans;
}

// main function
int main()
{
    string str = "aabacbebebe";
    int k = 3;
    cout << "Largest substring with " << k << " unique character is " << best(str, k);
    return 0;
}
