// Given two strings s and t, return the minimum window in s which will contain all the characters in t. 
// Video reference to understand the approach :- https://www.youtube.com/watch?v=iwv1llyN6mo&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=13

#include<bits/stdc++.h>
using namespace std;

// sliding window 
int best(string s, string t)
{
    int i=0,j=0;
    map<char,int>m;
    int ans = -1;
    for(auto &i:t)
        m[i]++;
    int count =m.size();
    // logic begins
    while(j < s.size())
    {
        if(m.find(s[j])!= m.end())
            m[s[j]]--;
    }
}

// main function
int main()
{
    string s = "";
    string t = "";
    cout<<"length of minimum window substring is "<<best(s,t);
    return 0;
}