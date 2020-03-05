#include<iostream>
using namespace std ;
int n,input[100010],k,ans[100010],out=0;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>input[i];
        input[i]%=k;
        ans[input[i]]++;
    }
    for(int i=0;i<=100009;i++)
    {
        if(ans[i]>0)
        {
            out++;
            //cout<<i<<' ';
        }
    }
    cout<<out<<endl;
    return 0;
}