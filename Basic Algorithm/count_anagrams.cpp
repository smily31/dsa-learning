// Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.
// Video reference to understand the code :-> https://www.youtube.com/watch?v=MW4lJ8Y0xXk&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=5
#include<bits/stdc++.h>
using namespace std;


// Sliding Window Technique
int best(string s, string p)
{
    int i=0,j=0;          // start and end of window
    int k= p.size();      // size of the window
    int ans = 0;          // to store count of occurence of anagrams
    map<char,int> m;      // to store count of all different character present in pattern
    for(auto i:p)
        m[i]++;
    int c = m.size();     // to store count of different char present in map

    // logic begins
    while(j < s.length())
    {
        // this is the calc. we needed
        if(m.find(s[j]) != m.end())
        {
            m[s[j]]--;                              
            if(m[s[j]] == 0)
                c--;
        }

        if(j-i+1 < k)
            j++;                // getting to the window size
        else if(j-i+1 == k)
        {
            // finding answer
            if(c == 0)
                ans++;
            // calc. befor shifting the window -reverse calc.
            if(m.find(s[i]) != m.end())
            {
                m[s[i]]++;
                if(m[s[i]] == 1)
                    c++;
            }
            i++;
            j++;
        }
    }
    return ans;
}

// main function
int main()
{
    string s = "aabaabaa";
    string p = "aaba";
    cout<<"Number of occurences of anagrams of string "<<p<<" is "<<best(s,p);
    return 0;
}