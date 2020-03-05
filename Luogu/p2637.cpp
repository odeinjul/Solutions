#include<iostream>
#include<algorithm>
using namespace std;
int p[1010];
bool cmp(int x,int y)
{
    return x<y;
}
int main()
{
    int n,m,sum=-1,ans=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>p[i];
    }
    sort(p+1,p+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(p[i]*(m-i+1)>ans)
        {
            ans=p[i]*(m-i+1);
            sum=p[i];
        }
    }
    cout<<sum<<' '<<ans<<endl;
    return 0;
}