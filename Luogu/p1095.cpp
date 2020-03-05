#include<iostream>
#include<cstdio>
using namespace std;
int m,s,t;
int f[300010];
int main()
{
    cin>>m>>s>>t;
    for(int i=1;i<=t;i++)
    {
        if(m>=10)
        {
            f[i]=f[i-1]+60;
            m-=10;
        }
        else
        {
            f[i]=f[i-1];
            m+=4;
        }
    }
    for(int i=1;i<=t;i++)
    {
        if(f[i]<f[i-1]+17)
        {
            f[i]=f[i-1]+17;
        }
        if(f[i]>=s)
        {
            cout<<"Yes"<<endl<<i<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl<<f[t]<<endl;
    return 0;
}