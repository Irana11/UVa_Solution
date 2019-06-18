
#include<stdio.h>
#include<math.h>
#define sz 32780
int ara[sz],prime[16400],root,i,j,k;

void sieve()
{
    k=0;
    root=sqrt(sz);
    for(i=2;i<sz;i++)
    {
        ara[i]=1;
    }
    for(i=2;i<=(sz/2);i++)
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
    int d,e,n;
    int count;
    sieve();

    while((scanf("%d",&e))==1&&e!=0)
    {
        i=0;
        count=0;
        d=0;
        n=e/2;
        while(prime[i]<=n&&i<k)
        {
            d=e-prime[i];
            i++;
            if(ara[d]==1)
            {
                count++;
            }
            d=e;
        }
        printf("%d\n",count);
    }
    return 0;


}
