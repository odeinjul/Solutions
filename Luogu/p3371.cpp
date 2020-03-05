#include<iostream>
#include<queue>

const long long inf=2147483647;
const int maxn=10005;
const int maxm=500005;
using namespace std;
int n,m,s,head[maxn],cnt=0;
bool vis[maxn];
long long dis[maxn];

struct nodes{
    int next,to,dist;
}edge[maxm];

void add(int from,int to,int w){
    cnt++;
    edge[cnt].to=to;
    edge[cnt].dist=w;
    edge[cnt].next=head[from];
    head[from]=cnt;
}
void spfa(int s){
    dis[s]=0;
    queue <int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=0;i=edge[i].next){
            int v=edge[i].to;
            if(dis[u]+edge[i].dist<dis[v]){
                dis[v]=dis[u]+edge[i].dist;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}
void dji(int s)
{
    int now=s;
    long long minn;
    while(!vis[now]){
            vis[now]=1;
            for(int i=head[now];i!=0;i=edge[i].next){
                if(!vis[edge[i].to]&&dis[edge[i].to]>dis[now]+edge[i].dist){
                    dis[edge[i].to]=dis[now]+edge[i].dist;
                }
            }
            minn=inf;
            for(int i=1;i<=n;i++){
                if(!vis[i]&&minn>dis[i]){
                    minn=dis[i];
                    now=i;
                }
            }
    }
}
int main(){
    cin>>n>>m>>s;
    int from,to,w;
    for(int i=1;i<=n;i++)
        dis[i]=inf;
    for(int i=1;i<=m;i++){
        cin>>from>>to>>w;
        add(from,to,w);
    }
    int now=s;
    dis[s]=0;
    long long minn;
    spfa(s);
    for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
}