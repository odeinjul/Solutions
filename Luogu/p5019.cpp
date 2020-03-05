#include<iostream>
using namespace std;
int n,map[100010],last,ans=0;;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>map[i];
    }
    ans=map[1];
    for(int i=2;i<=n;i++)
    {
        if(map[i]>map[i-1])
        ans+=map[i]-map[i-1];
    }
    cout<<ans<<endl;
    return 0;
}