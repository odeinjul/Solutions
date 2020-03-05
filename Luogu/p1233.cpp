#include<iostream>
#include<algorithm>
using namespace std;
struct sticks
{
    int l,w;
}st[5010];
int n,dp[5010]={0},ans=0;
int cmp(sticks a,sticks b)
{
    return a.l>b.l;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>st[i].l>>st[i].w;
    }
    sort(st+1,st+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(st[i].w>dp[ans])
        {
            dp[ans+1]=st[i].w;
            ++ans;
        }
        else
        {
            int l=1,r=ans;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(dp[mid]>=st[i].w)
                {
                    r=mid;
                }
                else
                {
                    l=mid+1;
                }
            }
            dp[l]=st[i].w;
        }
    }
    cout<<ans<<endl;
    return 0;
}