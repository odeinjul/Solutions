#include<iostream>
using namespace std;
int n;
int map[50][50];
int posx,posy,now=2;
int main()
{
    cin>>n;//r,l
    map[1][n/2+1]=1;
    posx=1,posy=n/2+1;
    while(now<=n*n)
    {
        if(posx==1&&posy!=n)
        {
            map[n][posy+1]=now;
            posx=n;
            posy=posy+1;
        }
        else if(posx!=1&&posy==n)
        {
            map[posx-1][1]=now;
            posx=posx-1;
            posy=1;
        }
        else if(posx==1&&posy==n)
        {
            map[2][n]=now;
            posx=2;
            posy=n;
        }
        else
        {
            if(!map[posx-1][posy+1])
            {
                map[posx-1][posy+1]=now;
                posx=posx-1;
                posy=posy+1;
            }
            else
            {
                map[posx+1][posy]=now;
                posx=posx+1;
                posy=posy;
            }
        }
        now++;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<map[i][1];
        for(int j=2;j<=n;j++)
        {
            cout<<' '<<map[i][j];
        }
        cout<<endl;
    }
}