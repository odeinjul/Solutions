#include<iostream>
#define min(a,b) a<b?a:b
#define ll long long
using namespace std;
ll n,m,cost=0,ci[100010],t[100010],a[100010],c[100010],b[100010];
int main()
{
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        cin>>t[i];
    }
    for(ll i=1;i<=m-1;i++)
    {
        if(t[i]<t[i+1])
        {
            ci[t[i]]++;
            ci[t[i+1]+1]--;
        }
        else
        {
            ci[t[i+1]]++;
            ci[t[i]+1]--;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        ci[i]+=ci[i-1]; 
    }
    for(ll i=1;i<=n-1;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        cost+=min(a[i]*ci[i],c[i]+b[i]*ci[i]);  
        //cout<<i<<' '<<cost<<endl;
    }
    cout<<cost<<endl;
    return 0;
}