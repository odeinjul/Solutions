#include<iostream>
#include<algorithm>
using namespace std;
struct millk
{
    int p,a;
}milk[5010];
int cmp(millk a,millk b)
{
    return a.p<b.p;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>milk[i].p>>milk[i].a;
    }
    sort(milk,milk+m,cmp);
    int i=0,cnt=0;
    while(n>0)
    {
        if(milk[i].a<n)
        {
            cnt+=milk[i].p*milk[i].a;
            n-=milk[i].a;
        }
        else
        {
            cnt+=n*milk[i].p;
            break;
        }
        //cout<<milk[i].p<<' '<<milk[i].a<<endl;
        i++;
    }
    cout<<cnt<<endl;
    return 0;
}
