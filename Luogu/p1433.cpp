#include<iostream>
#include<cmath>
using namespace std;
int n,eat[20],already_eat;
double mindis=9999999;
struct cheeses
{
    double x,y;
}cheese[20];
double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(double disnow,double x,double y)
{
    if(disnow>mindis)
        return ;
    if(already_eat==0)
    {
        mindis=disnow;
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(eat[i]==0)
        {
            eat[i]=1;
            already_eat--;
            double temp_dis=dis(x,y,cheese[i].x,cheese[i].y);
            dfs(disnow+temp_dis,cheese[i].x,cheese[i].y);
            already_eat++;
            eat[i]=0;
        }
        else
            continue;
    }
    return ;
}
int main()
{
    cin>>n;
    already_eat=n;
    for(int i=0;i<n;i++)
        cin>>cheese[i].x>>cheese[i].y;
    dfs(0,0,0);
    printf("%.2f",mindis);
    cout<<endl;
    return 0;
}