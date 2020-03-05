#include<iostream>
#include<cstring>
using namespace std;
string input;
int p1,p2,p3;
char s,t;
void work(char l,char r)
{
    if(p1==1)
    {
        if(p3==1)
        {
            for(int i=l+1;i<r;i++)
            {
                for(int j=1;j<=p2;j++)
                {
                    cout<<(char)i;
                }
            }
        }
        if(p3==2)
        {
            for(int i=r-1;i>l;i--)
            {
                for(int j=1;j<=p2;j++)
                {
                    cout<<(char)i;
                }
            }
        }
    }
    else if(p1==2)
    {
        if('0'<=l&&'9'>=r)
        {
            if(p3==1)
            {
                for(int i=l+1;i<r;i++)
                {
                    for(int j=1;j<=p2;j++)
                    {
                        cout<<(char)i;
                    }
                }
            }
            if(p3==2)
            {
                for(int i=r-1;i>l;i--)
                {
                    for(int j=1;j<=p2;j++)
                    {
                        cout<<(char)i;
                    }
                }
            }
        }
        else
        {
            l=l-'a'+'A';
            r=r-'a'+'A';
            if(p3==1)
            {
                for(int i=l+1;i<r;i++)
                {
                    for(int j=1;j<=p2;j++)
                    {
                        cout<<(char)i;
                    }
                }
            }
            if(p3==2)
            {
                for(int i=r-1;i>l;i--)
                {
                    for(int j=1;j<=p2;j++)
                    {
                        cout<<(char)i;
                    }
                }
            }
        }
    }
    else
    {
        for(int i=1;i<=p2*(r-l-1);i++)
        cout<<'*';
    }
    return ;
}
int main()
{
    cin>>p1>>p2>>p3;
    cin>>input;
    for(int i=0;i<input.length();i++)
    {
        s=input[i-1];t=input[i+1];
        if(input[i]=='-')
        {
            if(i==0)
            {
                cout<<'-';
                //cout<<2;
                continue;
            }
            if(i==input.length()-1)
            {
                cout<<'-';
                //cout<<3;
                continue;
            }
            if((s<t)&&(('0'<=s&&t<='9')||('a'<=s&&t<='z')))
            {
                work(s,t);
                //cout<<5;
            }
            else
            {
                cout<<'-';
                //cout<<1;
            }
        }
        else
        {
            cout<<input[i];
            //cout<<4;
        }
    }
    cout<<endl;
    return 0;
}