#include<iostream>
#include<queue>
using namespace std;
int n,input[500010];
long long ans;
queue <int> tmp;
void work(int l,int r)
{
    if(l==r)return ;
    int mid=(l+r)/2;
    work(l,mid);
    work(mid+1,r);
    int l_now=l,r_now=mid+1;
    while(l_now<=mid&&r_now<=r)
    {
        if(input[l_now]<=input[r_now])
            tmp.push(input[l_now++]);
        else
        {
            tmp.push(input[r_now++]);
            ans+=(mid-l_now+1);
        }
    }
    while(l_now<=mid)
    {
        tmp.push(input[l_now++]);
    }
    while(r_now<=r)
    {
        tmp.push(input[r_now++]);
    }
    for(int i=l;i<=r;i++)
    {
        input[i]=tmp.front();
        tmp.pop();
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>input[i];
    }
    work(1,n);
    cout<<ans<<endl;
    return 0;
}