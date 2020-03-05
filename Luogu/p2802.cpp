#include<iostream>
using namespace std;
int m,n;
int minstep=99999;
int map[20][20],vis[20][20];
int dirx[5]={0,1,0,-1};
int diry[5]={1,0,-1,0};
int homex,homey,startx,starty;
void dfs(int step,int x,int y,int heart)
{
    if(heart==0)//die
        return ;
    if(map[x][y]==4)
        heart=6;
    //cout<<step<<' '<<x<<' '<<y<<' '<<heart<<' '<<map[x][y]<<endl;
    if(map[x][y]==3)//get home
    {
        if(step<minstep)
            minstep=step;
        return ;
    }
    //start move
    for(int i=0;i<4;i++)
    {
        //map[x+dirx[i]][y+diry[i]]
        int xn=x+dirx[i],yn=y+diry[i];
        if((map[xn][yn]==0)||(xn<0)||(yn<0)||(xn>n)||(yn>m)||(vis[xn][yn]==1))
            continue;
        else
        {
            vis[xn][yn]=1;
            dfs(step+1,xn,yn,heart-1);
            vis[xn][yn]=0;
        }
    }
    return ;
}
int main()
{
    cin>>n>>m;//m行n列
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vis[i][j]=0;
            cin>>map[i][j];
            if(map[i][j]==2)
            {
                startx=i;
                starty=j;
            }
            if(map[i][j]==3)
            {
                homex=i;
                homey=j;
            }
        }
    }
    vis[startx][starty]=1;
    dfs(0,startx,starty,6);
    if(minstep<99999)
    {
        cout<<minstep<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}