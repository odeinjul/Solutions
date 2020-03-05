#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int t[10010],maxx=-1;
    int rock[30010];
    memset(rock,0,sizeof(rock));
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
        rock[t[i]]=1;
        maxx=max(maxx,t[i]);
    }
    int a=k,ans;
    for(int i=0;i<=maxx;i++)
    {   
        if(i==maxx&&a>0)
        {
            cout<<"NO RESULT"<<endl;
            return 0;
        }
        if(rock[i])
            a--;
        if(a==0)
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl; 
	return 0;
}