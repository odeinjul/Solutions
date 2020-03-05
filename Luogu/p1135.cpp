#include<iostream>
#include<cstring>
using namespace std ;
int main()
{
    int n,s,t,map[210][210];
    cin>>n>>s>>t;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            map[i][j]=map[j][i]=100000000;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(i+a<=n)
            map[i][i+a]=1;
        if(i-a>=1)
            map[i][i-a]=1;
    }
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            
            for(int j=1;j<=n;++j)
            {
                //cout<<i<<' '<<j<<' '<<k<<endl;;
                if(map[i][j]>map[i][k]+map[k][j])
                {
                    map[i][j]=map[i][k]+map[k][j];
                }
            }
        }
    }

    if(map[s][t]<100000000)
        cout<<map[s][t]<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}