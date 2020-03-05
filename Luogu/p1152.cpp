#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[1000000]={0};
int b[1000000]={0};
int main()
{
    cin>>n;
    int ans=n-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n;i++)
    {
        b[abs(a[i-1]-a[i])]=1;
    }
    for(int i=1;i<=n-1;i++)
    {
        ans-=b[i];
    }
    if(ans==0)
        cout<<"Jolly"<<endl;
    else
        cout<<"Not jolly"<<endl;
}