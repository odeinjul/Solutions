#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt=0,j;
int main()
{
    cin>>n;
    for(int i=1;i*2<=n;i++)
    {
        cnt=0;
        for(j=i;j<n;j++)
        {
            cnt+=j;
            if(cnt>=n)break;
        }
        if(cnt==n)
            cout<<i<<' '<<j<<endl;
    }
}