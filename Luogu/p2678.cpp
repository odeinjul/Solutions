#include<iostream>
#include<algorithm>
using namespace std;
int n,l,m,map[500010],tmp[500010];
bool check(int len)
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(map[i]<len)
        {
            ans++;
            map[i+1]+=map[i];
            //cout<<i<<' '<<map[i]<<' '<<map[i+1]<<endl;
        }
    }
    for(int i=n;i>=1;i--)
    {
        map[i]=tmp[i]-tmp[i-1];
    }
    //cout<<ans<<' '<<m<<endl;
    if(ans>m) return 0;
    else return 1;
}
int main()
{
    cin>>l>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp[i];
    }
    for(int i=n;i>=1;i--)
    {
        map[i]=tmp[i]-tmp[i-1];
    }
    if(n==0)
    {
        cout<<l<<endl;
        return 0;
    }
    if(m==0)
    {
        cout<<*max_element(map+1,map+1+n)<<endl;
        return 0;
    }
    int l=1,r=1000000001,mid;
    while(l+1<r)
    {
        mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
        //cout<<l<<' '<<r<<endl;
    }
    cout<<l<<endl;
    return 0;
}