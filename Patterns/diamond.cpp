#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    // loop for straight triangle
    for(int i=1;i<=n;i++)    // loop for row
    {
        for(int j=1;j<=n-i;j++)   // loop for space
           cout<<" ";
        for(int j=1;j<=2*i-1;j++)  // loop for stars
           cout<<"*";
        cout<<endl;
    }

    // loop for inverted triangle
    for(int i=n;i>=1;i--)    // loop for row
    {
        for(int j=1;j<=n-i;j++)   // loop for space
           cout<<" ";
        for(int j=1;j<=2*i-1;j++)  // loop for stars
           cout<<"*";
        cout<<endl;
    }
    return 0;
}