#include<bits/stdc++.h>
using namespace std;

// return the index where pattern matches in text
// this is the most common and famous problem in MS wors search or say google search
// to solve this there are many algo present 

// Naive approach-> TC-O((n-m+1)*m)
void naive(const string &str, const string &s)
{
    int n=str.length();
    int m=s.length();
    for(int i=0;i<=n-m;i++)
    {
        int j;
        for(j=0;j<m;j++)
        {
            if(s[j]!=str[i+j])
                break;
        }
        if(j==m)
            cout<<i<<" ";
    }
}

// Improved naive approach  for pattern having distinct characters
// TC-O(n)  
void improvedNaive(const string &str, const string &s)
{
    int n=str.length();
    int m=s.length();
    for(int i=0;i<=n-m;)
    {
        int j;
        for(j=0;j<m;j++)
        {
            if(s[j]!=str[i+j])
                break;
        }
        if(j==m)
            cout<<i<<" ";
        if(j==0)
            i++;
        else    
            i+=j;   // shifting by j since j no of element didnt match so shift it ahead as all characters are distinct
    }
}
int main()
{
    string str="babcdddaababc";
    string s="abc";
    improvedNaive(str,s);
    return 0;
}
