#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int n,maxn=-1,vis[21];
string in[21],start;
int check(string a,string b,int k)
{
    int lena=a.length();
    for(int i=0;i<k;i++)
    {
        if(a[lena-k+i]!=b[i])
            return false;
    }
    return true;
}
void add(string &a,string b,int k)
{
    int lenb=b.length();
    for(int i=k;i<lenb;i++)
    {
        a+=b[i];
    }
}
void bfs(string now)
{
    int len=now.length();
    maxn=max(len,maxn);
    for(int i=0;i<n;i++)
    {
        if(vis[i]>=2)
            continue;
        int len1=in[i].length();
        for(int j=1;j<len1;j++)
        {
            if(check(now,in[i],j))
            {
                string tmp=now;
                add(tmp,in[i],j);
                if(tmp==now)
                    continue;
                vis[i]++;
                bfs(tmp);
                vis[i]--;
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    cin>>start;
    bfs(start);
    cout<<maxn;
    return 0;
}