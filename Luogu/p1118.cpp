#include <bits/stdc++.h>
using namespace std;
int n,sum,tra[13][13],ans[13],use[13];
void tran()
{
    tra[1][1]=1;
    for(int i=2;i<=12;i++)
    {
        for(int j=1;j<=i;j++)
        {
            tra[i][j]=tra[i-1][j]+tra[i-1][j-1];
        }
    }
}
void dfs(int deep,int s)
{
    if(s>sum)
        return ;
    if(deep>n)
    {
        if(s==sum)
        {
            cout<<ans[1];
            for(int i=2;i<=n;i++)
            {
                cout<<' '<<ans[i];
            }
            cout<<endl;
            exit(0);
        }
            return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(use[i]==0)
        {
            use[i]=1;
            ans[deep]=i;
            dfs(deep+1,s+i*tra[n][deep]);
            use[i]=0;
        }
    }
}
int main()
{
    cin>>n>>sum;
    tran();
    dfs(1,0);
    return 0;
}