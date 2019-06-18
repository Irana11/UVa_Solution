
#include<stdio.h>
#include<math.h>
#define sz 10000005

int ara[sz],prm[sz];
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
            prm[k]=i;
            k++;
        }
    }
}

int main()
{
    long long n,d,m,max;
    int rt,cnt;
    sieve();
    while((scanf("%lld",&n))==1&&n!=0)
    {
        if(n<0)
        {
            n=n*(-1);
        }

        rt=sqrt(n);

        max=0;
        cnt=0;
        i=0;

        while(prm[i]<=rt&&i<k)
        {

            if(n%prm[i]==0)
            {
                cnt++;
                while(n%prm[i]==0)
                {
                    n=n/prm[i];

                }
                 if(prm[i]>max)
                {
                    max=prm[i];

                }
            }

            i++;
        }

        if(n!=1)
        {
            max=n;
            cnt++;
        }

        if(cnt>1)
        {
            printf("%lld\n",max);
        }
        else
        {
            printf("-1\n");
        }


    }
    return 0;
}
