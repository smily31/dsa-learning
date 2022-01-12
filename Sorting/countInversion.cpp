// We can call Inversion as if i<j and a[i]>a[j]
// We need to count the number of inversion in an array

#include<bits/stdc++.h>
using namespace std;

int countAndMerge(int a[], int l, int m , int r)
{
    int n1=m-l+1,n2=r-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
        left[i] = a[l+1];
    for(int i=0;i<n2;i++)
        right[i]=a[n1+i];
    int res = 0,i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            a[k] = left[i];
            i++;
        }
        else 
        {
            a[k]=right[j];
            j++;
            res +=(n1-i);
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=right[j];
        j++;
        k++;
    }
    return res;
}

int countInv(int a[], int l, int r)
{
    int res =0;
    if(l<r)
    {
        int m = l+(r-l)/2;
        res += countInv(a,l,m);
        res += countInv(a,m+1,r);
        res += countAndMerge(a,l,m,r);
    }
    return res;
}

int main()
{
    int a[]={2,5,1,6,3,9,6,8};
    int n=8;
    cout<<"ans is "<<countInv(a,0,n-1);
    return 0;
}