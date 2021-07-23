#include<bits/stdc++.h>
using namespace std;

// This is the basic problem to understand Multiple recursion call 
// Find fibonacci of nth number

int fibonacci(int n)
{
    if(n<=2)
        return 1;
    int a = fibonacci(n-1);
    int b = fibonacci(n-2);
    return a+b;
}


// main function
int main()
{
    int n;
    cin>>n;
    cout<<"Fibonacci is = "<<fibonacci(n)<<endl;
    return 0;
}