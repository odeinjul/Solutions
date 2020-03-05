#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,cnt=0;
    cin>>n;
    long long test[200010],pre=0;
    for(int i=1;i<=n;i++)
    {
        cin>>test[i];
    }
    sort(test+1,test+n+1);
    pre=test[1];cnt=1;
    for(int i=2;i<=n+1;i++)
    {
        if(test[i]==pre)cnt++;
        else
        {
            cout<<pre<<' '<<cnt<<endl;
            cnt=1;pre=test[i];
        }
    }
    return 0;
}