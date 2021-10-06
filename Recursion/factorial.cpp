#include<bits/stdc++.h>
using namespace std;

// To understand basic recursion concept this problem is must to do
// To find a factorial of a number 'n'

int factorial(int n)
{
    if(n<=1)
        return 1;
    
    return n * factorial(n-1);    // recurrence relation
}

// main function
int main()
{
    int n;
    cin>>n;
    cout<<"Factorial is = "<<factorial(n)<<endl;
    return 0;
}