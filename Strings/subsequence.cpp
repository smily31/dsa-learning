#include<bits/stdc++.h>
using namespace std;

// To check if given string is subsequence of other or not 

// iterative solution TC-O(n+m)   AS-O(1)  --better--
// here we are checking from first element of string2 till last of it in string 1
bool iterative(const string &str, int n, const string &s, int m)
{
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(str[i]==s[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }
    if(j==m)
        return true;
    else
        return false;
}

// recursive solution TC-O(n+m)   AS-O(n+m)-{for function call stack}
// here we are checking from last element till first of string2 
bool recursive(const string &str, int n, const string &s, int m)
{
    if(m==0)
        return true;
    if(n==0)
        return false;
    if(str[n-1]==s[m-1])
        return recursive(str, n-1, s , m-1);
    else
        return recursive(str, n-1,s,m);
}
int main()
{
    string str = "geeksforgeeks";
    string s = "t";
    int l1 = str.length();
    int l2 = s.length();
    bool ans = recursive(str,l1,s,l2);
    if(ans)
        cout<<"Subsequence is present \n";
    else
        cout<<"Not present\n";

    return 0;
}