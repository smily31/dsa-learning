#include<bits/stdc++.h>
using namespace std;

// To give the index of first occuring leftmost repeating character
// it has so many approaches to solve this

// Naive Approach-> traversering through every character and compairing it with rest others
// TC-O(n^2)
int naive(const string &str,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
            if(str[i]==str[j])
                return i;
    }
    return -1;
}

// Better Approach-> create constant count array to store frequency of each character then again loop 
// through string to find first occurence of character with frequwncy>1
// TC-O(n)   AS-constantO(CHAR)
int better(const string &str,int n)
{
    const int CHAR = 26;
    int count[CHAR] = {0};
    for(int i=0;i<n;i++)
    {
        count[str[i]-'a']++;
    }
    for(int i=0;i<n;i++)
    {
        if(count[str[i]-'a']>1)
            return i;
    }
    return -1;
}

// Efficient Approach-1
// TC-O(n)  AS-constant
int efficient1(const string &str, int n)
{
    const int CHAR=26;
    int index[CHAR];  // to store index of every character
    int res = INT_MAX;
    fill(index,index+CHAR,-1);  // to fill array with -1
    for(int i=0;i<n;i++)
    {
        int fi=index[str[i]-'a'];
        if(fi==-1)     // if char. is not visited then store its index
            index[str[i]-'a']=i;
        else          // if visited earlier then we'll store min index of repeated char
            res=min(res,fi);
    }
    return (res==INT_MAX)?-1:res;
}

// Efficient Approach-2
// visiting the character from n-1th index ->then when we got to character that is earlier visited we willl store
// its index as result then at the end result will have index of leftmost repeated character
int efficient2(const string &str,int n)
{
    const int CHAR=26;
    bool visited[CHAR]={0};
    int res = INT_MAX;
    for(int i=n-1;i>=0;i--)
    {
        if(visited[str[i]-'a'] == false)
            visited[str[i]-'a']=true;
        else
            res = i;
    }
    return (res==INT_MAX)?-1:res;
}
int main()
{
    string s="abbddjca";
    int n = s.length();
    int ans = efficient2(s,n);
    cout<<"Index of leftmost repeating character is "<<ans<<"\n";
    return 0;
}