#include<bits/stdc++.h>
using namespace std;
int n,dirx[9]={0,1,1,0,-1,-1,-1,0,1},diry[9]={0,0,-1,-1,-1,0,1,1,1};
char G[110][110],ans[110][110];
char hh[10]={' ','y','i','z','h','o','n','g'};
bool dfs(int num,int x,int y,int to)
{

}
int main()
{
	cin>>n;
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>G[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(G[i][j]=='y')
			{
				for(int to=1;to<=8;to++)
					dfs(1,i,j,to);
			}
		}
	}
	return 0;
}