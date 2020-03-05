#include<iostream>
#include<cmath>
using namespace std;
int n,m,map[110][110],dp[110][110],maxx=-1;;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>map[i][j];
            //cout<<i<<' '<<j<<' '<<map[i][j]<<endl;
            dp[i][j]=map[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(map[i][j])
            {
                dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                //cout<<n<<' '<<m<<' '<<dp[i][m]<<endl;
                maxx=max(maxx,dp[i][j]);
            }
        }
    }
    cout<<maxx<<endl;
    return 0;
}