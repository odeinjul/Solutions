#include<iostream>
using namespace std;
int n,w,dp[400100];
struct node
{
    int we,va;
}obj[1100];
int main()
{
    int index=0;
    cin>>n>>w;
    for(int i=1;i<=n;i++)
    {
        int c=1,wor,wei,k;
        cin>>wor>>wei>>k;
        while(k-c>0)
        {
            k-=c;
            obj[++index].we=wei*c;
            obj[index].va=wor*c;
            c*=2;
        }
        obj[++index].we=k*wei;
        obj[index].va=wor*k;
    }
    for(int i=1;i<=index;i++)
    {
        for(int j=w;j>=obj[i].we;j--)
        {
            dp[j]=max(dp[j],dp[j-obj[i].we]+obj[i].va);
        }
    }
    cout<<dp[w]<<endl;
    return 0;
}