bool su(int a){
    if(a==1) return 0;
    if(a==2||a==3) return 1;
    if(a%6!=1&&a%6!=5) return 0;
    int temp=sqrt(a);
    for(int i=5;i<=temp;i+=6)
    {
        if(a%i==0||a%(i+2)==0) return 0;
    }
    return 1;
}