#include<iostream>
#include<algorithm>
using namespace std;
int n,input[1000],dp1[1000],dp2[1000],len1=0,len2=0,ans=0,l[1000],r[1000];
int cmp(int a,int b)
{
    return a>b;
}
void le(int i)
{
    if(i==1)
    {
        len1=0;
        return ;
    }
    if(i==2)
    {
        if(input[1]<=input[2])
        {
            len1=0;
            return ;
        }
    }
    len1=1;
    dp1[1]=input[1];
    for(int j=2;j<=i;j++)
    {
        if(input[j]>dp1[len1])dp1[++len1]=input[j];
        else
        {
            int k=lower_bound(dp1+1,dp1+1+len1,input[j])-dp1;
            dp1[k]=input[j];
        }
    }
}
void ri(int i)
{
    if(i==n)
    {
        len2=0;
        return ;
    }
    if(i==n-1)
    {
        if(input[n]>=input[n-1])
        {
            len2=0;
            return ;
        }
    }
    len2=1;
    dp2[i+1]=input[i+1];
    for(int j=i+2;j<=n;j++)
    {
        if(input[j]<dp2[len2])dp2[++len2]=input[j];
        else
        {
            int k=lower_bound(dp2+1,dp2+1+len2,input[j],cmp)-dp2;
            dp2[k]=input[j];
        }
        
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>input[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int x=1;x<=n;x++)
        {
            dp1[x]=dp2[x]=0;
        }
        if(i==n)
        {
            le(i);
            ans=max(ans,len1+len2);
            len2=0;
            //cout<<i<<' '<<len1<<' '<<len2<<endl;
            continue;
        }
        if(i==1)
        {
            ri(i);
            len1=0;
            ans=max(ans,len1+len2);
            //cout<<i<<' '<<len1<<' '<<len2<<endl;
            continue;
        }
        le(i);
        ri(i);
        ans=max(ans,len1+len2);
        //cout<<i<<' '<<len1<<' '<<len2<<endl;
    }
    cout<<n-ans<<endl;
    return 0;
}