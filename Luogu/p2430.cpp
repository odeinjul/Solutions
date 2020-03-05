#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int wky_e,lw_e,m,n,w[5010],f[5010],t[5010],knowledge[5010];
    cin>>wky_e>>lw_e>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        knowledge[i]=tmp*(lw_e/wky_e);
        //cout<<knowledge[i]<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        int p,q;
        cin>>p>>q;
        t[i]=knowledge[p];
        w[i]=q;
    }
    int time;
    cin>>time;
    for(int i=0;i<=n;i++)
    {
        f[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=time;j>=1;j--)
        {
            if(j>=t[i])
            f[j]=max(f[j],f[j-t[i]]+w[i]);
            else
            f[j]=f[j];
            //cout<<j<<' '<<f[j]<<' '<<f[j-t[i]]+w[i]<<endl;
        }
    }
    cout<<f[time]<<endl;
    return 0;
}