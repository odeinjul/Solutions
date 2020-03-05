#include<iostream>
using namespace std;
int n,k,ans[100010];
void work(int now)
{
    //cout<<now<<endl;
    int a=k;
    for(int i=1;i<=a;i++)
    {
        if(now-i>=0)
        {
            //cout<<now<<' '<<now-i<<endl;
            ans[now]+=ans[now-i];
            ans[now]=ans[now]%100003;
        }
    }
    if(now<n)
        work(now+1);
    else 
        return;
}
int main()
{
    cin>>n>>k;
    ans[0]=1;
    ans[1]=1;
    work(2);
    cout<<ans[n]<<endl;
    return 0;
}