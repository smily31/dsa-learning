#include<bits/stdc++.h>
using namespace std;


// TC - theta(n)   --> T(n)=T(n-1)+(1)
// AS - theta(n)

void print(int n)
{
    if(n==0)
        return;
    print(n-1);
    cout<<n<<" ";
}

int main()
{
    int n;
    cin>>n;
    print(n);
    return 0;
}