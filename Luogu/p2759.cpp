#include<iostream>
#include<cmath>
using namespace std;
long long x,n;
bool check(long long x)
{
    if(log10(x)*x>=n-1)
        return 1;
    else
        return 0;
}
int main()
{
    cin>>n;
    if(n>=10)
    {
        long long l=1,r=n+1,mid=0;
        while(l+1<r)
        {
            mid=(l+r)/2;
            if(check(mid))
                r=mid;
            else
                l=mid;
        }
        cout<<r<<endl;
    }
    else if(n==1)
    {
        cout<<1<<endl;
    }
    else
    {
        long long l=1,r=n+11,mid=0;
        while(l+1<r)
        {
            {
                
            }
            mid=(l+r)/2;
            if(check(mid))
                r=mid;
            else
                l=mid;
        }
        cout<<r<<endl;
    }
    return 0;
}