#include<iostream>
using namespace std;
const int mod =99999997;
const int maxn=10000005;
long long n,x[maxn],p[maxn],ans=0;
struct fire{
    int hi,num;
}l1[maxn],l2[maxn];
bool cmp(fire a,fire b){
    return a.hi<b.hi;
}
void msort(int l,int r){
    if(l==r)return ;
    int mid=(l+r)>>1;
    msort(l,mid);msort(mid+1,r);
    int l_now=l,r_now=mid+1;
    while(l_now<=mid&&r_now<=r){
        if(x[l_now]<=x[r_now])
        {
            l_now++;r_now++;
        }
        else
        {
            l_now++;r_now++;
            ans=(ans+mid-l_now+1)%mod;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>l1[i].hi,l1[i].num=i;
    for(int i=1;i<=n;i++)
        cin>>l2[i].hi,l2[i].num=i;
    sort(l1+1,l1+1+n,cmp);
    sort(l2+1,l2+1+n,cmp);
    for(int i=1;i<=n;i++)
        x[l2[i].num]=l1[i].num;
    msort(1,n);
    cout<<ans<<endl;
    return 0;
}