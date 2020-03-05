#include <bits/stdc++.h>
using namespace std;
int n,le,ri,sum[20010],ans[20010],add[20010],lent,lens,lenn=0;
struct peoples
{
    int l,r;
    long long l_r;
}peo[1100];
int cmp(peoples a,peoples b)
{
    return a.l_r<b.l_r;
}
void times(int x)
{
    memset(add,0,sizeof(add));
    for(int i=1;i<=ans[0];i++)
    {
        ans[i]*=x;
        add[i+1]=ans[i]/10;
        ans[i]%=10;
    }
    for(int i=1;i<=ans[0]+4;i++)
    {
        ans[i]+=add[i];
        if(ans[i]>=10)
        {
            ans[i+1]+=ans[i]/10;
            ans[i]%=10;
        }
        if(ans[i]!=0)
        {
            ans[0]=max(ans[0],i);
        }
    }
}
void divide(int x)
{
    memset(add,0,sizeof(add));
    int r=0;
    for(int i=ans[0];i>=1;i--)
    {
        r=r*10+ans[i];
        add[i]=r/x;
        r%=x;
        if(add[0]==0&&add[i]!=0)
        {
            add[0]=i;
        }
    }
}
bool compare()
{
    if(sum[0]==add[0])
    {
        for(int i=add[0];i>=1;i--)
        {
            if(add[i]>sum[i])return 1;
            if(add[i]<sum[i])return 0;
        }
    }
    if(add[0]>sum[0])return 1;
    if(add[0]<sum[0])return 0;
}
void copy_()
{
    memset(sum,0,sizeof(sum));
    for(int i=add[0];i>=0;i--)
    {
        sum[i]=add[i];
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cin>>peo[i].l>>peo[i].r;
        peo[i].l_r=peo[i].l*peo[i].r;
    }
    sort(peo+1,peo+1+n,cmp);
    ans[0]=1,ans[1]=1;
    for(int i=1;i<=n;i++)
    {
        times(peo[i-1].l);
        divide(peo[i].r);
        if(compare())
        {
            copy_();
        }
    }
    for(int i=sum[0];i>=1;i--)
    {
        cout<<sum[i];
    }
    cout<<endl;
    return 0;
}