#include<iostream>
using namespace std;
int n,m;
int fa[10010];
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
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1)
        {
            ope(x,y);
        }
        else
        {
            if(com(x,y)==1)
                cout<<"Y"<<endl;
            else
                cout<<"N"<<endl;
        }
    }
    return 0;
}