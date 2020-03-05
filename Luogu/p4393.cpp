#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int input[1000010];
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    for(int i=1;i<n;i++)
    {
        ans+=max(input[i],input[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}