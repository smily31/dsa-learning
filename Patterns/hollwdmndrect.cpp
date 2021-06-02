#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    // loop for upper half
    for(int i=1;i<=n;i++)   //loop for row
    {
        for(int j=1;j<=n-i;j++)  //instead of space star loop 
        cout<<"*";
        for(int j=1;j<=2*i-1;j++)  // diamond border loop
        {
            if(j==1||j==2*i-1)
            cout<<"*";
            else
            cout<<" ";           
        }
        for(int j=1;j<n+1-i;j++)   // after star space loop
        cout<<"*";
        cout<<endl;
    }

    // loop for lower half
        for(int i=n;i>=1;i--)   //loop for row
    {
        for(int j=1;j<=n-i;j++)  //instead of space star loop 
        cout<<"*";
        for(int j=1;j<=2*i-1;j++)  // diamond border loop
        {
            if(j==1||j==2*i-1)
            cout<<"*";
            else
            cout<<" ";           
        }
        for(int j=1;j<n+1-i;j++)   // after star space loop
        cout<<"*";
        cout<<endl;
    }
    return 0;
}