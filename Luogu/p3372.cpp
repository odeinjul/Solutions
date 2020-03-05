#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 100010;
int n,m;
long long tag[maxn*4],ans[maxn*4],a[maxn];
void push_up(int p){
	ans[p]=ans[2*p]+ans[2*p+1];
}
void build(int p,int l,int r){
	if(l==r){
		ans[p]=a[l];
		return ;
	}
	else{
		int mid=(l+r)>>1;
		build(2*p,l,mid);
		build(2*p+1,mid+1,r);
		push_up(p);
	}
}
void change(int p,long long k,int l,int r){
	tag[p]+=k;
	ans[p]+=(long long)1*k*(r-l+1);
}
void push_down(int p,int l,int r){
	int mid=(l+r)>>1;
	change(2*p,tag[p],l,mid);
	change(2*p+1,tag[p],mid+1,r);
	tag[p]=0;
}
void update(int ql,int qr,int l,int r,int p,long long k){
	if(ql<=l&&qr>=r){
		change(p,k,l,r);
		return ;
	}
	if(tag[p])push_down(p,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)update(ql,qr,l,mid,2*p,k);
	if(qr>mid)update(ql,qr,mid+1,r,2*p+1,k);
	push_up(p);
}
long long ask(int ql,int qr,int l,int r,int p){
	if(ql<=l&&qr>=r){
		return ans[p];
	}
	if(tag[p])push_down(p,l,r);
	int mid=(l+r)>>1;
	long long sum=0;
	if(ql<=mid)sum+=ask(ql,qr,l,mid,2*p);
	if(qr>mid)sum+=ask(ql,qr,mid+1,r,2*p+1);
	return sum;
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int opt,x,y;
		long long z;
		cin>>opt>>x>>y;
		if(opt==1){
			cin>>z;
			//cout<<"OK"<<endl;
			update(x,y,1,n,1,z);
		}
		else cout<<ask(x,y,1,n,1)<<endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}