#include<iostream>
using namespace std;
int n,k,input[5010],cf[5010],ans1=9999,ans2;
int main()
{
    cin>>n;
    char inpuu;
    for(int i=1;i<=n;i++)
    {
        cin>>inpuu;
        if(inpuu=='B')
            input[i]=0;
        else
            input[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        memset(cf,0,sizeof(cf));
        int m=0;bool flag=1,b;
        for(int j=1;j<=n;j++)
        {
            b^=cf[j];
            if(!(input[j]^b))
            {
                if(j+i-1>n){flag=0;break;}
                b^=1,cf[j+i]^=1;
                m++;
            }
        }
        if(flag){if(m<ans1)ans1=m,ans2=i;}
    }
    cout<<ans2<<' '<<ans1<<endl;
    return 0;
}