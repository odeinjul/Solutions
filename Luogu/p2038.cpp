#include<iostream>
using namespace std;
int d,n,map[200][200],total,pos,ans=-1;
int main()
{
    cin>>d>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y,k;
        cin>>x>>y>>k;
        map[x][y]=k;
    }
    for(int i=0;i<=128;i++)
    {
        for(int j=0;j<=128;j++)
        {
            int xs,xt,ys,yt;
            xs=i-d;xt=i+d;ys=j-d;yt=j+d;
            if(xs<0)xs=0;
            if(ys<0)ys=0;
            if(xt>128)xt=128;
            if(yt>128)yt=128;
            total=0;
            for(int q=xs;q<=xt;q++)
            {
                for(int w=ys;w<=yt;w++)
                {
                    total+=map[q][w];
                }
            }
            if(total==ans)
            {
                pos++;
            }
            if(total>ans)
            {
                ans=total;
                pos=1;
            }
        }
    }
    cout<<pos<<' '<<ans;
    return 0;
}