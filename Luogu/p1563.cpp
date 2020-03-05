#include<iostream>
#include<cstring>
using namespace std;
struct mengbiers
{
    int face_to;
    string name;
}mens[1000010];
int n,m,position=1;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>mens[i].face_to>>mens[i].name;
        if(mens[i].face_to==0)mens[i].face_to=-1;
    }
    for(int i=1;i<=m;i++)
    {
        int towards,num;
        cin>>towards>>num;
        if(towards==0)towards=-1;
        position+=(-1*towards*num*mens[position].face_to);
        while(position<=0)position+=n;
        position%=n;
        if(position==0)position=n;
    }
    cout<<mens[position].name<<endl;
    return 0;
}