#include<bits/stdc++.h>
using namespace std;

// to check a string is palindrome or not 
// recursion practice

int checkPalindrome(string s, int i, int n)
{
    if(i>=n/2)
        return 1;
    if(s[i] != s[n-i-1])
        return 0;
    checkPalindrome(s,i+1,n);
    
}

// main function
int main()
{
    string s;
    cin>>s;
    int n = s.length();
    cout<<"Palindrome check: "<<checkPalindrome(s,0,n)<<endl;
    return 0;
}