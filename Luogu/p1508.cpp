#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,map[205][205],dp[205][205];
int main()
{
    cin>>m>>n;
    //memset(dp,0xff,sizeof(dp));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>map[i][j];
            dp[i][j]=map[i][j];
            //cout<<map[i][j]<<endl;
            //i行j列
        }
        if(i>1)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=max(max(dp[i-1][j],dp[i-1][j-1]),dp[i-1][j+1])+map[i][j];
                //cout<<dp[i][j]<<' ';
            }
        }
        //cout<<endl;
    }
    cout<<max(max(dp[m][n/2+1],dp[m][n/2]),dp[m][n/2+2])<<endl;
    return 0;
}