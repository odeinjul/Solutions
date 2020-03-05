#include<iostream>
using namespace std;
int fa[400010],cnt[400010],n,m,k,ans=0;
int find(int x)
{
    if(fa[x]==x)
    {
        return x;
    }
    else
    {
        fa[x]=find(fa[x]);
        return fa[x];
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(find(x)!=find(y))
        {
            fa[x]=y;
        }
    }
    for(int i=1;i<=2m;i++)
    {
        fa[i]=find(i);
        cnt[fa[i]]++;
    }
    for(int i=1;i<=2m;i++)
    {
        if(cnt[fa[i]]>0)ans++;
    }
    cout<<ans<<endl;
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        
    }
    return 0;
}