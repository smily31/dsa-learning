#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    //loop for pattern
    for(int i=1;i<=n;i++)   //loop for row
    {
        for(int j=1;j<=i;j++)  // loop for column
        {
            if((i+j)%2==0)  //even sum of indices have 1  
            cout<<"1 ";
            else
            cout<<"0 ";            
        }
        cout<<endl;
    }
    return 0;
}