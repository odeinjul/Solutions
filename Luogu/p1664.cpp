#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n=0,lost=0,ans=0,day=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp==0)
            lost++;
        else
        {
            if(lost>0)
            day-=pow(2,lost-1);
            if(day<0)day=0;
            day++;
            lost=0;
            if(1<=day&&day<3)ans++;
            if(3<=day&&day<7)ans+=2;
            if(7<=day&&day<30)ans+=3;
            if(30<=day&&day<120)ans+=4;
            if(120<=day&&day<365)ans+=5;
            if(day>=365)ans+=6;
            //cout<<i+1<<' '<<ans<<' '<<day<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}