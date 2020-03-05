#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF = 0x7f7f7f7f; 
const int N = 1024;
struct edge{
    int to,cost;
};
typedef pair<int,int> P; 
vector<edge> G[N],G1[N];
int d[N],d1[N],n,m;
int dij(int s,int t)
{
    priority_queue<P,vector<P>,greater<P> > pq;
    for(int i=1;i<=n;i++)
    {
        d[i] = INF;
    }
    d[s] = 0;
    pq.push(P(0,s));
    while(!pq.empty())
    {
    P temp = pq.top(); 
    int u = temp.second; 
    pq.pop();
    if(temp.first > d[temp.second])
        continue; 
    for(int i=0;i<G[u].size();i++)
    {
        edge e = G[u][i]; 
        if(d[e.to] > d[u] + e.cost)
        {
            d[e.to] = d[u] + e.cost; 
            pq.push(P(d[e.to],e.to));
        }
    }
}
cout<<t<<' '<<d[t]<<endl;
return d[t];
}

int dij1(int s,int t)
{
    priority_queue<P,vector<P>,greater<P> > pq;
    for(int i=1;i<=n;i++)
    {
        d1[i] = INF;
    }
    d1[s] = 0;
    pq.push(P(0,s));
    while(!pq.empty())
    {
    P temp = pq.top(); 
    int u = temp.second; 
    pq.pop();
    if(temp.first > d1[temp.second])
        continue; 
    for(int i=0;i<G1[u].size();i++)
    {
        edge e = G1[u][i]; 
        if(d1[e.to] > d1[u] + e.cost)
        {
            d1[e.to] = d1[u] + e.cost; 
            pq.push(P(d1[e.to],e.to));
        }
    }
}
cout<<t<<' '<<d1[t]<<endl;
return d1[t];
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back((edge){v,w});
        G1[v].push_back((edge){u,w});
    }
    long long ans=0;
    for(int i=2;i<=n;i++)
    {
        ans+=dij(1,i);
        ans+=dij1(i,1);
    }
    cout<<ans<<endl;
    return 0;
}