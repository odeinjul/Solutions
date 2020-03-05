#include<iostream>
using namespace std;
struct dot{
    int left,right,father;
}map[200];
int n,root;
void work(int root)
{
    cout<<(char)root;
    if(map[root].left!='*')work(map[root].left);
    if(map[root].right!='*')work(map[root].right);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char input,l,r;
        cin>>input>>l>>r;
        if(i==0)root=input;
        map[input].left=l;
        map[input].right=r;
        map[map[input].left].father=map[map[input].right].father=input;
    }
    work(root);
    cout<<endl;
    return 0;
}