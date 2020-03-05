#include<iostream>
#include<vector>
using namespace std;
int n,m;
int fa[10010];
struct edge{
    int u,v,w;
};
edge edge1[200100];
int cmp(edge a,edge b)
{
    return a.w<b.w;
}
void fst()
{
    for(int i=1;i<=n;i++)
    fa[i]=i;
}
int find(int x)
{
    //cout<<2131;
    if(fa[x]==x)
        return x;
    else
    {
        //cout<<212211221;
        fa[x]=find(fa[x]);
        //cout<<x<<' '<<fa[x]<<endl;
        return fa[x];
    }
}
void ope(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
    fa[x]=y;
    else return;
}
bool com(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
    return true;
    else
    return false;
}
int main()
{
    cin>>n>>m;
    fst();
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        edge1[i].u=x;
        edge1[i].v=y;
        edge1[i].w=z;
    }
    sort(edge1+1,edge1+1+m,cmp);
    int cnt=0,ans=0;
    for(int i=1;i<=m;i++)
    {
        if(!com(edge1[i].u,edge1[i].v))
        {
            ope(edge1[i].u,edge1[i].v);
            ans+=edge1[i].w;
            cnt++;
        }
    }
    if(cnt>n-1)
    cout<<"orz"<<endl;
    else
    cout<<ans<<endl;
    return 0;
}