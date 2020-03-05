#include<iostream>
using namespace std;
int n,M,T,m[1100],t[1100],dp[1100][1100];
int main()
{
    cin>>n>>M>>T;
    for(int i=1;i<=n;i++)
    {
        cin>>m[i]>>t[i];
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=M;i>=m[k];i--)
        {
            for(int j=T;j>=t[k];j--)
            {
                if(i>=m[k]&&j>=t[k])
                {
                    dp[i][j]=max(dp[i-m[k]][j-t[k]]+1,dp[i][j]);
                }
            }
        }
    }
    cout<<dp[M][T]<<endl;
    return 0;
}