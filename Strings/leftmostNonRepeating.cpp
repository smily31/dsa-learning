#include<bits/stdc++.h>
using namespace std;

// TO find the index of leftmost non repeating character of the string

// Naive Approach-
// TC-O(n^2)    
int naive(const string &str, int n)
{
    for(int i=0;i<n;i++)
    {
        bool flag= false;
        for(int j=0;j<n;j++)
        {
            if(i!=j && str[i]==str[j])
            {
                flag = true;
                break;
            }
        }
        if(flag == false)
            return i;
    }
    return -1;
}

// Better Approach -> 2 times traversal of string
// TC-O(n)  AS-constant
int better(const string &str, int n)
{
    const int CHAR=26;
    int count[CHAR] = {0};
    for(int i=0;i<n;i++)
    {
        count[str[i]-'a']++;
    }
    for(int i=0;i<n;i++)
    {
        if(count[str[i]-'a'] == 1)
            return i;
    }
    return -1;
}

// Efficient Approach -1 time traversal of string and 1 constant traversal
// TC-O(n)    AS-constant
// this can be used to find non repeating in stream of strings also
int efficient(const string &str, int n)
{
    const int CHAR=26;
    int index[CHAR];
    fill(index, index+CHAR, -1);
    int res = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(index[str[i]-'a'] == -1)
            index[str[i]-'a']=i;
        else
            index[str[i]-'a']=-2;   //for repeating characters
    }
    for(int i=0;i<CHAR;i++)
    {
        if(index[i]>=0)
            res=min(res,index[i]);
    }
    return(res==INT_MAX)?-1:res;
}

int main()
{
    string s = "aabbcc";
    int n = s.length();
    int ans = efficient(s,n);
    cout<<"Index at which leftmost non repeating character occurs "<<ans<<'\n';
    return 0;
}