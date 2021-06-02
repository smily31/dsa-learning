#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int sp=2*n-2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cout<<"*";
        for(int j=1;j<=sp;j++)
        cout<<" ";
        for(int j=1;j<=i;j++)
        cout<<"*";
        cout<<endl;
        sp-=2;
    }
     sp=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        cout<<"*";
        for(int j=1;j<=sp;j++)
        cout<<" ";
        for(int j=1;j<=i;j++)
        cout<<"*";
        cout<<endl;
        sp+=2;
    }
    return 0;
}