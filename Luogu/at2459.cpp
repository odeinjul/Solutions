#include<iostream>
#include<algorithm>
using namespace std;
int x,a,b,c,n;
int main()
{
    cin>>x>>a>>b>>c>>n;
    if(n<=b)
    {
        cout<<min(x*n,a)<<endl;
    }
    else
    {
        cout<<min(x*n,a+c*(n-b))<<endl;
    }
    return 0;
}