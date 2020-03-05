#include<iostream>
#include<algorithm>
using namespace std;
struct coin{
    int x,y;
};
int cmp(coin a,coin b)
{
    if(a.y==b.y)
    return a.x<b.x;
    else
    return a.y<b.y;
}
coin a[100];
int n,g;
int main()
{
    cin>>g;
    while(g>0)
    {
        g--;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y;
        }
        sort(a+1,a+n+1,cmp);
        int bj=0;
        a[0].x=0;
        a[0].y=0;
        for(int i=1;i<=n;i++)
        {
            if(abs(a[i-1].x-a[i].x)>abs(a[i].y-a[i-1].y))
            {
            cout<<"Notabletocatch"<<endl;
            bj=1;
            break;
            }
        }
        if(!bj)
        cout<<"Abletocatch"<<endl;
    }
}