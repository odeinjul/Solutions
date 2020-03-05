#include<iostream>
#include<string>
using namespace std ;
int main()
{
    string a,b,c,d;
    int key[26]={0},cnt=0;
    cin>>a>>b>>c;
    for(int i=0;i<a.length();i++)
    {
        if(key[a[i]-'A']==0)
        {
            key[a[i]-'A']=(b[i]-'A');
            //cout<<key[a[i]-'A']<<' '<<(a[i]-'A')<<endl;
            cnt++;
        }
        else
        {
            if(key[a[i]-'A']!=(char)(b[i]-'A'))
            {
                cout<<"Failed"<<endl;
                return 0;
            }
        }
    }
    if(cnt<26)
    {
        cout<<"Failed"<<endl;
        return 0;
    }
    //for(int i=0;i<26;i++)
   // {
    //    cout<<(char)('A'+i)<<' '<<(char)('A'+key[i])<<endl;
    //}
    for(int i=0;i<c.length();i++)
    {
        cout<<(char)('A'+key[c[i]-'A']);
    }
    cout<<endl;
    return 0;
}