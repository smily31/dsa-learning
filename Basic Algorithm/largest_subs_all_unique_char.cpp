// Find the length of largest substring with all unique character
// Video reference to understand the code :-> https://www.youtube.com/watch?v=L6cffskouPQ&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=11

#include <bits/stdc++.h>
using namespace std;

// Variable sized sliding window solution
int best(string str)
{
    int i = 0, j = 0;
    int ans = INT_MIN;
    map<char, int> m;

    // logic begins
    while (j < str.size())
    {
        //j - i + 1 we needed to check all unique character which will be equal to size of the window
        m[str[j]]++;
        if (m.size() == j - i + 1)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (m.size() < j - i + 1)
        {
            while (m.size() < j - i + 1)
            {
                m[str[i]]--;
                if (m[str[i]] == 0)
                    m.erase(str[i]);
                i++;
            }
            if (m.size() == j - i + 1)
                ans = max(ans, j - i + 1);
            j++;
        }
    }
    return ans;
}

// main function
int main()
{
    string str = "bbbb";
    cout << "Largest substring with all unique character is " << best(str);
    return 0;
}