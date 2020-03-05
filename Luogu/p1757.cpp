#include<iostream>
using namespace std;
int n,m,gr,dp[1100],c[101][20],cnt[1100],w[1100],v[1100];
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int ca;
        cin>>w[i]>>v[i]>>ca;
        gr=max(gr,ca);
        cnt[ca]++;
        c[ca][cnt[ca]]=i;
    }
    for(int k=1;k<=gr;k++)
    {
        for(int i=m;i>=0;i--)
        {
            for(int j=1;j<=cnt[k];j++)
            {
                if(i>=w[c[k][j]])
                dp[i]=max(dp[i],dp[i-w[c[k][j]]]+v[c[k][j]]);
            }
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}