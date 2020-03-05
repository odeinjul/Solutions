#include<iostream>
const int maxn=1000010;
using namespace std;
int n,m;
int tag[maxn<<2],ans[maxn<<2],input[maxn];
void push_up(int p)
{
    ans[p]=ans[2*p]+ans[2*p+1];
}
void build(int l,int r,int p)
{
    if(l==r)
	{
		ans[p]=input[l];
		return ;
	}
    int mid=(l+r)>>1;
    build(l,mid,2*p);
    build(mid+1,r,2*p+1);
    push_up(p);
}
void push_down(int l,int r,int p)
{
    int mid=(l+r)>>1;
	int k=tag[p];
    tag[2*p]+=k;
    tag[2*p+1]+=k;
    ans[2*p]+=(mid-l+1)*k;
    ans[2*p+1]+=(r-mid)*k;
	tag[p]=0;
}
void update(int pl,int pr,int l,int r,int p,int k)
{
    if(pl<=l&&r<=pr)
    {
        tag[p]+=k;
        ans[p]+=(l-r+1)*k;
		return ;
    }
    push_down(l,r,p);
    int mid=(l+r)>>1;
    if(pl<=mid)update(pl,pr,l,mid,2*p,k);
    if(pr>mid)update(pl,pr,mid+1,r,2*p+1,k);
    push_up(p);
}
int ask(int pl,int pr,int l,int r,int p)
{
    if(pl<=l&&r<=pr)
        return ans[p];
    int mid=(l+r)>>1;
    int val=0;
    if(pl<=mid)val+=ask(pl,pr,l,mid,2*p);
    if(pr>mid)val+=ask(pl,pr,mid+1,r,2*p+1);
    return val;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>input[i];
    }
    build(1,n,1);
    for(int i=1;i<=m;i++)
    {
        int op,x,y,k;
        cin>>op>>x>>y;
        if(op==1)
        {
            cin>>k;
            update(x,y,1,n,1,k);
        }
        if(op==2)
        {
            cout<<ask(x,y,1,n,1)<<endl;
        }
    }
    return 0;
}