#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
int n,m,a,b;
int map1[410][410];
bool vis[410][410];
int gox[8]={1,2,2,1,-1,-2,-2,-1},goy[8]={2,1,-1,-2,-2,-1,1,2};
struct xy
{
    int x,y;
}node,top;
void bfs(int x,int y,int step)
{
    map1[x][y]=step;
    vis[x][y]=1;
    queue<xy> q;
    node.x=x;
    node.y=y;
    q.push(node);
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        //cout<<top.x<<' '<<top.y<<endl;
        for(int i=0;i<8;i++)
        {
            int tx=top.x+gox[i],ty=top.y+goy[i];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&map1[tx][ty]==-1)
            {
                //cout<<tx<<' '<<ty<<endl;
                node.x=tx;
                node.y=ty;
                q.push(node);
                vis[tx][ty]=1;
                map1[tx][ty]=map1[top.x][top.y]+1;
            }
        }
    }
}
int main()
{
    cin>>n>>m>>a>>b;
    memset(map1,-1,sizeof(map1));
    memset(vis,0,sizeof(vis));
    bfs(a,b,0);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)
            printf("%-5d", map1[i][j]);
        printf("\n");
    }
    return 0;
}