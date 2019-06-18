
#include<stdio.h>

typedef long long i64;
//long long x;
i64 b,p,mod,m,x;

i64 bmod(i64 b,i64 p)
{
    m=mod;
    if(p==0)
    return 1;

    i64 x=bmod(b,p/2);
    x=(x*x)%m;
    if(p%2==1)
    {
        x=(x*(b%m))%m;
    }
    return x;
}

int main()
{
    i64 b,p,r;
    while((scanf("%lld%lld%lld",&b,&p,&mod))==3)
    {
        r=bmod(b,p);
        printf("%lld\n",r);
    }
    return 0;
}
