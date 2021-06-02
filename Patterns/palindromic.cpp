#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    //loop for pattern 
    for(int i=1;i<=n;i++)  //loop for row
    {
        for(int j=1;j<=n-i;j++)    // loop for space
        {
            cout<<" ";
        }
        for(int j=i;j>=1;j--)    // loop for descending number
        {
            cout<<j;
        }
        for(int j=2;j<=i;j++)    // loop for ascending number from 2
        {
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}