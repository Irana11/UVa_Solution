#include<stdio.h>

int main()
{
    int a,b,d,cnt;
    while(scanf("%d%d",&a,&b)==2)
    {
        cnt=a;
        while(1)
        {
            d=a/b;
            if(d<1)
            break;
            cnt+=d;
            a=d+a%b;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
