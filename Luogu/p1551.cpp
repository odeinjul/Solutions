#include<iostream>
using namespace std;
int fa[5010],n,m,p;
int find(int x)   //加速递归 
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        fa[find(a)]=find(b);
    }
    for(int i=1;i<=n;i++)
    {
        fa[i]=find(i);
        //cout<<fa[i]<<' '<<endl;
    }
    for(int i=1;i<=p;i++)
    {
        int a,b;
        cin>>a>>b;
        int aa=find(a),bb=find(b);
        if(aa!=bb)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}