#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,sum[10010],f[10010],num=1;;
struct jobs{
    int start,last;
}job[10010];
int cmp(jobs a,jobs b)
{
    return a.start > b.start;
}
int main()
{
    cin>>n>>k;
    memset(job,0,sizeof(job));
    memset(sum,0,sizeof(sum));
    memset(f,0,sizeof(f));
    for(int i=1;i<=k;i++)
    {
        cin>>job[i].start>>job[i].last;
        sum[job[i].start]++;
    }
    sort(job+1,job+1+k,cmp);
    for(int i=n;i>=1;i--)
    {
        if(sum[i]==0)
            f[i]=f[i+1]+1;
        else
        {
            for(int j=1;j<=sum[i];j++)
            {
                f[i]=max(f[i],f[i+job[num].last]);
                num++;
            }
        }
    }
    cout<<f[1]<<endl;
    return 0;
}