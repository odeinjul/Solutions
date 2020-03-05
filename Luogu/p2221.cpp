#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int G[11000][11000];
int dis[11000];
bool man[11000]={0};
int main(){
    int n;
    cin>>n;
    char a,b;
    int w,a1,b1;
    memset(dis,0x3f,sizeof(dis));
    memset(G,0x3f,sizeof(G));
    memset(man,0,sizeof(man));
    for (int i=0;i<n;i++)
        {cin>>a>>b>>w;
        if(a>='a'){
            a1=(int)(a-'a');
          //  cout<<a1<<' '<<a<<endl;
            }
        else{
            a1=(int)(a-'A');
            man[a1]=1;
         //   cout<<a1<<' '<<a<<endl;
         }
        if(b>='a'){
            b1=(int)(b-'a');
        //  cout<<b1<<' '<<b<<endl;
            }
        else{
            b1=(int)(b-'A');
            man[b1]=1;
        //  cout<<b1<<' '<<b<<endl;
        }
        G[a1][b1]=G[b1][a1]=w;
       // cout<<G[a1][b1]<<endl;
        }
    int z=25;
    for(int i=0;i<26;i++)
    {
        dis[i]=G[z][i]=G[i][z];
        G[i][i]=0;
        //cout<<i<<' '<<dis[i]<<endl<<endl;
    }
    dis[z]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            dis[j]=min(dis[j],dis[i]+G[i][j]);
            dis[i]=min(dis[i],dis[j]+G[i][j]);
           // cout<<i<<' '<<j<<' '<<dis[i]<<' '<<dis[j]<<endl;
        }
    }
    int ans=0x7f7f7f;
    char hh;
    for(int i=0;i<=n;i++){
        if((dis[i]<ans)&&(dis[i]>=0)){
            if(man[i]==1){
            //  cout<<dis[i]-ans<<endl;
                ans=dis[i];
            //  cout<<dis[i]<<endl;
                hh=(char)(47+i);
            //  cout<<i<<' '<<ans<<' '<<hh<<' '<<endl;

            }
            }

    }
    cout<<hh<<' '<<ans;
    return 0;
}