#include<stdio.h>
#define sz 1000010
int ara[sz],prime[sz];
int i,j,k;

void sieve()
{
    k=0;
    for(i=2;i<sz;i++)
    {
        ara[i]=1;
    }
    for(i=2;i<sz;i++)
    {
        if(ara[i]==1)
        {
            for(j=2;i*j<sz;j++)
            {
                ara[i*j]=0;
            }
            prime[k]=i;
            k++;
        }

    }
}
int main()
{
    int n,d1,d2,a,b,flg;
    sieve();
    while((scanf("%d",&n))==1&&n!=0)
    {
        printf("%d:\n",n);
        flg=0;
        i=0;

        while(i<k&&prime[i]<=(n/2))
        {
            d1=n-prime[i];
            if(ara[d1]==1)
            {
                a=prime[i];
                b=d1;
                flg=1;
                break;
            }
            i++;
        }
        if(flg==1)
        {
            printf("%d+%d\n",a,b);
        }
        else
        {
            printf("NO WAY!\n");
        }

    }
    return 0;
}
