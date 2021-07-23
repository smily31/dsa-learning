#include<bits/stdc++.h>
using namespace std;

// Print all subsquence -> good to learn pick not pick concept
// little bit backtracking

void subsquence(int arr[],int n, int i, vector<int> &v)
{
    if(i==n)
        {
            for(auto i:v)
                cout<<i<<" ";
            cout<<endl;
            return ;
        }

        v.push_back(arr[i]);
        subsquence(arr,n,i+1,v);
        v.pop_back();
        subsquence(arr,n,i+1,v);
}

// main function
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int>v;
    subsquence(arr,n,0,v);
    return 0;
}