/*
dfs
*/
#include <iostream>
using namespace std ;
int r,c,map[110][110],ans[110][110],vis[110][110];
int gox[4]={0,1,0,-1},goy[4]={1,0,-1,0};
int dfs(int x,int y)
{
    if(ans[x][y]>0) return ans[x][y];
    int maxn=-1;
    for(int i=0;i<4;i++)
    {
        int nx=x+gox[i];
        int ny=y+goy[i];
        if(nx<0||ny<0||nx>=c||ny>=r||map[nx][ny]>=map[x][y])
            continue;
        maxn=max(maxn,dfs(nx,ny)+1);
    }
    ans[x][y]=max(maxn,ans[x][y]);
    return ans[x][y];
}
int main()
{
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>map[j][i];//(x,y)
        }
    }
    int maxxn=-1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            maxxn=max(maxxn,dfs(j,i)+1);
        }
    }
    cout<<maxxn<<endl;
    return 0;
}