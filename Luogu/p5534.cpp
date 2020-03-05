#include<iostream>
using namespace std;
long long a1,a2,n;
int main()
{
    cin>>a1>>a2>>n;
    long long d=a2-a1;
    long long sum=(a1+a1+d*(n-1))*n/2;
    cout<<sum<<endl;
    return 0;
}