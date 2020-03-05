#include<iostream>
#define ll long long
using namespace std;
long long n,k,a,b,s;
long long hh(ll n,ll k,ll a,ll b){
		if(k==1)
			cout<<(n-1)*a<<endl;
		
    ll ans=0;
    ll c,d=n;
    c=d;
    while(n>1){
        if(n%k==0){
        //  cout<<"hhh"<<' '<<n<<endl;
            if((n-(n/k))*a>b){
            n/=k;
            ans+=b;
        //  cout<<' '<<ans<<endl;
        //  cout<<"aaa"<<endl;
        //  cout<<n<<endl; 
            }
            else {
        ans+=a;
        n-=1;
    //  cout<<' '<<ans<<endl;
    //  cout<<d<<endl; 
        }
        }
        else {
        ans+=a;
        n-=1;
    //  cout<<' '<<ans<<endl;
    //  cout<<d<<endl; 
    }
    }
    return ans;
}
int main(){
    cin>>s;
    for(int i=0;i<s;i++){
        cin>>n>>k>>a>>b;
        cout<<hh(n,k,a,b)<<endl;
    }
    return 0;
}