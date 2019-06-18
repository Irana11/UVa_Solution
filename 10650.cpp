#include<stdio.h>

#define sz 32010
int ara[sz],prime[sz],s[sz];
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
    int a,b,d1,d2,x,m;
    sieve();
    while((scanf("%d%d",&a,&b))==2)
    {
        if(a==0&&b==0)
        break;
        int tmp;
        if(a>b)
        {
            tmp=a;
            a=b;
            b=tmp;
        }
        i=0;
        m=0;
        while(prime[i]<=b)
        {
            d1=prime[i+1]-prime[i];
            d2=prime[i+2]-prime[i+1];
            if(d1==d2)
            {
                for(j=0;j<3;j++)
                {
                    s[j]=prime[i];
                    m=i;
                    i++;
                }
                while(prime[i]-prime[i-1]==d1)
                {
                    s[j]=prime[i];
                    m=i;
                    i++;
                    j++;

                }
                if(s[0]>=a&&s[j-1]<=b)
                {
                    for(x=0;x<j;x++)
                    {
                        if(x==0)
                        {
                            printf("%d",s[0]);
                        }
                        else
                        {
                            printf(" %d",s[x]);
                        }
                    }
                    printf("\n");
                }
                i=m-1;
            }

            i++;
        }
    }
    return 0;
}
