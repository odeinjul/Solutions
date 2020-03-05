#include<bits/stdc++.h>
using namespace std;
int n,d,mod=1000000009,input[600100],maxn=1;
long long ans=1;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>input[i];
    }
    sort(input+1,input+1+n);
    for(int i=2;i<=n;i++)
    {
        while((input[i]-d)>input[maxn]&&maxn<i)
        {
            maxn++;
        }
        ans*=i-maxn+1;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}