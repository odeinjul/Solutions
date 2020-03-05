#include<iostream>
#include<algorithm>
using namespace std;
int n,input[100010],dp[100010],len=0;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    n=1;
    while(cin>>input[n])
    {   
        n++;
    }
    n--;
    dp[1]=input[1];
    len=1;
    //LIS
    for(int i=2;i<=n;i++)
    {
        if(input[i]<=dp[len])
            dp[++len]=input[i];
        else
        {
            int j=upper_bound(dp+1,dp+len+1,input[i],cmp)-dp;
            dp[j]=input[i];
        }
    }
    cout<<len<<endl;
    len=1;
    for(int i=0;i<=n;i++)
    {
        dp[i]=0;
    }
    dp[1]=input[1];
    for(int i=2;i<=n;i++)
    {
        if(input[i]>dp[len])
        {
            dp[++len]=input[i];
        }
        else
        {
            int j=lower_bound(dp+1,dp+len+1,input[i])-dp;
            dp[j]=input[i];
        }
    }
    cout<<len<<endl;
    return 0;
}