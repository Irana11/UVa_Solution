#include<stdio.h>
int ara[105],prime[100],count[100],i,j,k;
void sieve()
{
    k=0;
    for(i=2;i<205;i++)
    {
        ara[i]=1;
    }
    for(i=2;i<105;i++)
    {
        if(ara[i]==1)
        {
            for(j=2;i*j<105;j++)
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
    int N,n,x,v;
    sieve();

    while((scanf("%d",&N))==1&&N!=0)
    {
        for(j=2;j<=100;j++)
        {
            count[j]=0;
        }

        for(x=2;x<=N;x++)
        {
            if(ara[x]==1)
            {
                count[x]++;
            }
            else
            {
                v=x;
                for(j=0;prime[j]<=x;j++)
                {

                    if(v%prime[j]==0&&j<k)
                    {
                        while(v%prime[j]==0)
                        {
                            n=v/prime[j];
                            count[prime[j]]++;
                            v=n;
                        }

                    }
                }

            }

        }
        for(i=0;prime[i]<=N;i++)
        {
            if(i==0)
            {
                printf("%3d! =%3d",N,count[2]);
            }
            else if(i==15)
            {
                printf("\n      %3d",count[prime[i]]);

            }
            else
            {
                printf("%3d",count[prime[i]]);
            }

        }
        printf("\n");
    }
        return 0;

}
