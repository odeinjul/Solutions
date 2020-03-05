/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int n,minn=0x3f3f3f3f;
vector <int> t[200001];
bool visited[200001];
void dfs(int x,int n,int z)
{
    //cout<<x<<' '<<n<<' '<<z<<endl;
    visited[x]=true;
    for(int i=0;i<t[x].size();i++)
    {
        if(!visited[t[x][i]])
            dfs(t[x][i],n+1,z);
        else
            minn=min(n,minn);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int tep;
        cin>>tep;
        t[i].push_back(tep);
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i,1,i);
        memset(visited,0,sizeof(visited));
    }
    cout<<minn<<endl;
    return 0;
}
*/
#include<cstdio>
#include<iostream>
using namespace std;
int f[200002],d[200002],n,minn,last;   
int fa(int x)
{
    if (f[x]!=x)                       
    {
        int last=f[x];                
        f[x]=fa(f[x]);                
        d[x]+=d[last];                
    }
    return f[x];
}
void check(int a,int b)
{
    int x=fa(a),y=fa(b);                
    if (x!=y) 
    {
        f[x]=y; 
        d[a]=d[b]+1;
    }   
    else 
        minn=min(minn,d[a]+d[b]+1);   
}
int main()
{
    int i,t;
    cin>>n;
    for (i=1;i<=n;i++) 
    {
        f[i]=i;  
        d[i]=0;
    }
    minn=0x7777777;
    for (i=1;i<=n;i++)
    {
        cin>>t;
        check(i,t);                
    }
    cout<<minn<<endl;
    return 0;
}