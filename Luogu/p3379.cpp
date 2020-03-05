#include<iostream>
#include<algorithm>
const int maxn=500010;
using namespace std;
struct edge{
    int next,to;
}e[maxn<<1];
int head[maxn],tot;
int depth[maxn],fa[maxn][25],lg[maxn];
void add(int x,int y){
    e[++tot].to=y;
    e[tot].next=head[x];
    head[x]=tot;
}
void dfs(int now,int fath){
    fa[now][0]=fath;depth[now]=depth[fath]+1;
    for(int i=1;i<=lg[depth[now]];++i)
        fa[now][i]=fa[fa[now][i-1]][i-1];
    for(int i=head[now];i;i=e[i].next)
            if(e[i].to!=fath)dfs(e[i].to,now);
}
int lca(int x,int y){
    if(depth[x]<depth[y])swap(x,y);
    while(depth[x]>depth[y])
        x=fa[x][lg[depth[x]-depth[y]]-1];
    if(x==y)return x;
    for(int k=lg[depth[x]-1];k>=0;--k)
        if(fa[x][k]!=fa[y][k])
            x=fa[x][k],y=fa[y][k];
    return fa[x][0];    
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<=n-1;++i){
        int x,y;cin>>x>>y;
        add(x,y);add(y,x);
    }
    for(int i=1;i<=n;i++)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    dfs(s,0);
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<endl;
    }
    return 0;
}