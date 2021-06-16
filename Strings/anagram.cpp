#include<bits/stdc++.h>
using namespace std;

// To check if the given string is anagram of other or not
// ANAGRAM -> both string should have same number of characters 
// TC-O(n)->where n is the length of string ::since CHAR is constant it does not affect TC
// AS->O(CHAR)

bool anagram(const string &str1, const string &str2)
{
    int l1=str1.length();
    int l2=str2.length();
    if(l1 != l2)  // both string shpuld have same length then only they can be anagram of each other
        return false;
    else 
    {
        const int CHAR = 256;
        int count[CHAR]={0};
        for(int i=0;i<l1;i++)
        {
            count[str1[i]]++;
            count[str2[i]]--;
        }
        for(int i=0;i<CHAR;i++)
        {
            if(count[i]!=0)
                return false;
        }
        return true;
    }
}

int main()
{
    string str1= "aaabc";
    string str2= "aboa";
    bool ans = anagram(str1,str2);
    if(ans)
        cout<<"Both string are anagram of each other\n";
    else
        cout<<"Strings are not anagram\n";
    return 0;
}