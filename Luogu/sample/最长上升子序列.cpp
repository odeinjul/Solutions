/* 
最长上升子序列(单调递增)
Points:
    1.*min_element(a,a+i):求数组a下标从0到ℹi间最小值
    2.*max_element(a,a+i):求数组a下标从0到ℹi间最大值
*/
//O(n^2)
#include<iostream>
#include<algorithm>
using namespace std;
int n,input[100010];
int dp[100010];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
        dp[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(input[i]>input[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int maxx=*max_element(dp,dp+n);
    cout<<maxx<<endl;
    return 0;
}

//O(nlogn)
#include<iostream>
using namespace std;
int input[100000];
int n;
int dp[100000];
int len=1;
int find(int x){
    int l=1,r=len,m;
    while(l<r){
        m=l+(r-l)/2;
        if(dp[m]>=input[x]){
            r=m;
        } 
        else{
            l=m+1;
        }
    }
    return l;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>input[i];
    dp[1]=input[1];
    for(int i=2;i<=n;i++){
        if(input[i]>dp[len]){
            dp[++len]=input[i];
        }
        else{
            int pos=find(i);
            dp[pos]=input[i];
        }
    }
    cout<<len<<endl;
    return 0;
}