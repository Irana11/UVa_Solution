#include<stdio.h>

#define a 46350
int ara[a];
int prime[a];
int s[a];
int i,j,k;

void sieve()
{
    k=0;

    for(i=2;i<a;i++)
    {
        ara[i]=1;
    }
    for(i=2;i<a;i++)
    {
        if(ara[i]==1)
        {
            for(j=2;i*j<a;j++)
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
    int n,b;
    sieve();

    while((scanf("%d",&n))==1&&n!=0)
    {

        j=0;
        b=n;
        if(b<0)
        {
            b=-b;
        }

        for(i=0;i<k;i++)
        {
            while(b%prime[i]==0&&b!=1)
            {
                b=b/prime[i];
                s[j]=prime[i];
                j++;
            }
        }
        if(b>1)
        {
            s[j]=b;
            j++;
        }
        if(n<0)
        {
            printf("%d = -1",n);
            for(i=0;i<j;i++)
            {
                printf(" x %d",s[i]);
            }

        }
        else
        {
            printf("%d =",n);
            for(i=0;i<j;i++)
            {
                if(i==0)
                {
                    printf(" %d",s[i]);
                }
                else
                {
                    printf(" x %d",s[i]);
                }

            }

        }
        printf("\n");
    }
return 0;
}
