#include<iostream>
#include<cstdio>
using namespace std;
double a,b,c,d,mid;
int cnt=0;
double f(double x)
{
    return x*x*x*a+x*x*b+x*c+d;
}
int main()
{
    cin>>a>>b>>c>>d;
    for(int x=-100;x<100;x++)
    {
        double l=x;double r=x+1;
        if(!f(l))
        {
            printf("%.2lf ",l);
            cnt++;
        }
        //else if(f(x2)==0)printf("%.2f",x2);
        if(f(l)*f(r)<0)
        {
            while(r-l>=0.001)
            {
                mid=(r+l)/2;
                if(f(mid)*f(r)<=0)
                {
                    l=mid;
                }
                else
                {
                    r=mid;
                }
            }
            printf("%.2lf ",r);
            cnt++;
        }
        if(cnt==3)break;
    }
    cout<<endl;
    return 0;
}