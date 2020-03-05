#include<iostream>
#include<string>
using namespace std;
int n,k;
int ans[210][10];
int main()
{
    cin>>n>>k;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++)
    {
        ans[i][0]=0;
        ans[i][1]=1;
    }
    for(int i=2;i<=k;i++)
    {
        ans[1][i]=0;
        ans[0][i]=0;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            if(j>i)
            {
                ans[i][j]=0;
            }
            else 
            {
                ans[i][j]=ans[i-1][j-1]+ans[i-j][j];
            }
        }
    }
    cout<<ans[n][k]<<endl;
    return 0;
}
/*
5 3
4 1 1

4 2

3 1
2 2


3 2
2 1
1 2

4 2
3 1
2 2

 */