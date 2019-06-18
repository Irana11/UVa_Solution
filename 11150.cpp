#include<stdio.h>

int main()
{
    int cnt,n,f,e;
    while(scanf("%d",&n)==1)
    {
        cnt=0;
        e=n;
        while(e>=3)
        {
            n=n+e/3;
            e=e/3+e%3;
        }
        if(e==2)
        {
            n++;
        }
        printf("%d\n",n);
    }
    return 0;
}
