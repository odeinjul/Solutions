#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int maxxx(double a)
{
    if(a<0)
        return -a;
    else
        return a;
}
int main()
{
    double l;
    double a,b;
    cin>>a>>b>>l;
    int a1=a,b1=b;
    a*=1.0;
    b*=1.0;
    int ans1=0,ans2=0;
    double m=9999999;
    for(int i=l;i>=1;i--)
    {
        for(int j=l;j>=1;j--)
        {
            if(gcd(i,j)!=1)
            continue;
            else
            {
                double x=i*1.0;
                double z=j*1.0;
                if((x*a<=b*z)&&(m>(b*z)-(x*a)))
                {
                    m=maxxx((b*z)-(x*a));
                    ans1=x;
                    ans2=z;
                }
            }
        }
    }
    cout<<ans2<<' '<<ans1<<endl;
    return 0;
}