#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int Get_Friend_Id(int n)
{
    //cout<<"Hello"<<endl;
        int ans=0;
        int sq=sqrt(n);
        for(int i=1;i<sq;i++)
        {
            if(n%i==0)
            ans+=i+n/i;
        }
        if(n%sq==0)
            ans+=sq;
        ans-=n;
        //cout<<ans<<' '<<n<<endl;
    return ans;
}
int main()
{
    int s;
    cin>>s;
    for(int i=s;;i++)
    {
        int tmp=Get_Friend_Id(i);
        if((Get_Friend_Id(tmp)==i)&&(tmp!=i))
        {
            cout<<i<<' '<<tmp<<endl;
            break;
        }
    }
    return 0;
}