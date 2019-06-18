#include<stdio.h>

#define sz 20000010
int ara[sz],prime[sz],a1[100005],a2[100005];
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
    j=1;
    for(i=0;i<k;i++)
    {
        if(prime[i+1]-prime[i]==2)
        {
            a1[j]=prime[i];
            a2[j]=prime[i+1];
            j++;
        }
    }
   // printf("%d\n",j);
}

int main()
{
    int n;
    sieve();

    while(scanf("%d",&n)==1)
    {
        printf("(%d, %d)\n",a1[n],a2[n]);
    }
    return 0;
}
