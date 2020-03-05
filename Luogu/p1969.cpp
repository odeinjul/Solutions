#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,fin[100010],cnt=0,now;
bool flag=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>fin[i];
    }
    cnt=now=fin[1];
    for(int i=1;i<=n;i++)
    {
        if(fin[i]>now)cnt+=fin[i]-now;
        now=fin[i];
    }
    cout<<cnt<<endl;
    return 0;
}