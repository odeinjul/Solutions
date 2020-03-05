#include<iostream>
#include<algorithm>
using namespace std;
long long b1,p1,k1,ans=1;
void ksm(long long b,long long p,long long k)
{
	while(p>0)
	{
		if(p%2==1)
		{
			ans=ans*b%k;
		}
		p/=2;
		b=b*b%k;
	}
}
int main()
{
	cin>>b1>>p1>>k1;
	ksm(b1,p1,k1);
	printf("%lld^%lld mod %lld=%lld",b1,p1,k1,ans%k1);
	cout<<endl;
    return 0;
}