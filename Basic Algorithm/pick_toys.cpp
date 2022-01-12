// there is big line of different kinds of toys
// we need to collect maximum number of toys

// Conditions :-
// * toys must be collected in continuous manner
// * there must be maximum of 2 different kind of toys

// Video to know problem and approach better :- https://www.youtube.com/watch?v=seOKHXB_w74&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=12

// Input : given a string
// Output : integer with max number of toys

#include <bits/stdc++.h>
using namespace std;

int best(string s)
{
    int i = 0, j = 0;
    int ans = 0, count = 0;
    map<char, int> m;
    // logic begins
    while (j < s.size())
    {
        m[s[j]]++;
        count++;
        if (m.size() < 2)
            j++;
        else if (m.size() == 2)
        {
            ans = max(ans, count);
            j++;
        }
        else
        {
            while (m.size() > 2)
            {
                m[s[i]]--;
                count--;
                if (m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            if (m.size() == 2)
                ans = max(ans, count);
            j++;
        }
    }
    return ans;
}

// main function
int main()
{
    string s = "abacccab";
    cout << "Maximum number of toys are " << best(s);
    return 0;
}