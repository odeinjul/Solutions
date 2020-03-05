#include<iostream>
using namespace std;
int a[1000005];
int n,m;
bool check(int k)
{
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>k)
            sum+=(long long)(a[i]-k);
    }
    return sum>=m;
}
int search(int x)
{
    int l=1,r=1000000001;
    while(l+1<r)
    {
        int mid=(l+r)/2;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    return l;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<search(m)<<endl;
    return 0;
}