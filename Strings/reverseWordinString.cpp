#include<bits/stdc++.h>
using namespace std;

// Reverse word in a string
// not writing naive solution

//function to reverse a string 
void reverse(string &str, int low, int high)
{
    while(low<=high)
    {
        swap(str[low],str[high]);
        low++;
        high--;
    }
}
// Logic-> first we will reverse each word then reverse whole string then we will got our desired 
// string in reverse order of word
void reverseWord(string &s,int n)
{
    int start =0;
    for(int end=0; end<n ;end++)
    {
        if(s[end] == ' ')
        {
        reverse(s,start,end-1);    // reversing every word
        start=end+1;
        }
    }
    reverse(s,start,n-1);   // to reverse last word
    reverse(s,0,n-1);    // now reverse whole string
}
int main()
{
    string str ="Welcome to my world";
    int n = str.length();
    cout<<str<<'\n';
    reverseWord(str,n);
    cout<<"After reversal of words : "<<str<<'\n';
    return 0;
}