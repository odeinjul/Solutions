#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int map[1010][1010],vis[1010][1010],n,m;
int gox[4]={0,1,0,-1},goy[4]={1,0,-1,0};
struct xy
{
    int x,y;
}node,top;
void work(int x,int y,int space,int last)
{
    queue<xy> q;
    stack<xy> s;
    vis[x][y]=1;
    space=1;
    last=map[x][y];
    node.x=x;
    node.y=y;
    q.push(node);
    s.push(node);
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        last=map[top.x][top.y];
        for(int i=0;i<4;i++)
        {
            int tx=top.x+gox[i];
            int ty=top.y+goy[i];
            if(tx<0||ty<0||tx>=n||ty>=n||vis[tx][ty]==1||map[tx][ty]==last)
            {
                continue;
            }
                space++;
                node.x=tx;
                node.y=ty;
                q.push(node);
                s.push(node);
                vis[node.x][node.y]=1;
        }
    }
    while(!s.empty())   
    {
        node=s.top();
        s.pop();
        map[node.x][node.y]=space;
        //cout<<node.x<<' '<<node.y<<' '<<map[node.x][node.y]<<endl;
    }
}

int main()
{
    cin>>n>>m;
    char tmp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           cin>>tmp;
           map[i][j]=tmp-'0';
        }
    }
    int cnt;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cnt++;
            if(vis[i][j]==0)
            work(i,j,cnt,0);
        }
    }
/*
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<map[i][i]<<' ';
        }
        cout<<endl;
    }
*/
    for(int i=0;i<m;i++)
    {
        int x,y;
        //cout<<233<<endl;
        cin>>x>>y;
        cout<<map[x-1][y-1]<<endl;
    }
    
    return 0;
}