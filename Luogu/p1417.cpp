#include<iostream>
#include<algorithm>
#include<cstring>
#define LL long long
using namespace std;
int n,T;
long long dp[100100],ans;
struct node
{
    int a,b,c;
}input[100100];
int cmp(node x,node y)
{
    return (LL)x.c*y.b<(LL)y.c*x.b;
}
int main()
{
    cin>>T>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>input[i].a;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>input[i].b;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>input[i].c;
    }
    sort(input+1,input+1+n,cmp);
    memset(dp,255,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=T;j>=0;j--)
        {
            if(dp[j]!=-1&&j+input[i].c<=T)
            dp[j+input[i].c]=max(dp[j+input[i].c],dp[j]+(LL)input[i].a-(LL)input[i].b*(LL)(j+input[i].c));
            //cout<<i<<' '<<j<<' '<<dp[j]<<' '<<dp[j-c[i]]+a[i]-b[i]*(T-j+c[i])<<endl;
        }
    }
    for(int i=0;i<=T;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}