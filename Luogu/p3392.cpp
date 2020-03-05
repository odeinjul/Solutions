#include<bits/stdc++.h>
using namespace std;
int G[60][60],r[60],w[60],b[60];
int main()
{
	int n,m;
	cin>>n>>m; 
	memset (r,0,sizeof(r));
	memset (w,0,sizeof(w));
	memset (b,0,sizeof(b));
	memset (G,0,sizeof(G));
	for(int i=1;i<=n;i++)
	{
		int cntr=0,cntw=0,cntb=0;
		char a;
		for(int j=1;j<=m;j++)
		{
			cin>>a;
			if(a=='R')
			{
				cntr++;
			}
			else if(a=='W')
			{	
				cntw++;
			}
			else
			{
				cntb++;
		    }
		}
		r[i]=r[i-1]+m-cntr;
		w[i]=w[i-1]+m-cntw;
		b[i]=b[i-1]+m-cntb;
				//cout<<i<<' '<<cntr<<' '<<r[i-1]<<' '<<r[i]<<endl;
				//cout<<1<<' '<<cntw<<' '<<w[i-1]<<' '<<w[i]<<endl;
				//cout<<2<<' '<<cntb<<' '<<b[i-1]<<' '<<b[i]<<endl;
	}
	int min_=999999;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(w[i]+b[j]-b[i]+r[n]-r[j]<min_)
				min_=w[i]+b[j]-b[i]+r[n]-r[j];
		}
	}
	cout<<min_;
	return 0;
}