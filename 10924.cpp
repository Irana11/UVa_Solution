
#include<stdio.h>
#include<string.h>
#define sz 1100
int ar[sz],n[sz];
int i,j,k,num;
void sieve()
{
    num=sz-5;
    long long i,j;
    k=0;
    k++;
    for(i=3;i<=num;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=num;j+=(i*2))
            {
                ar[j]=1;
            }

        }
        ar[i+1]=1;

    }
}
int main()
{
    char wrd[25];
    int sum,l;
    sieve();
    for(i=1,j=97;i<=26;i++,j++)
    {
        n[j]=i;
    }
    for(i=27,j=65;i<=52;i++,j++)
    {
        n[j]=i;
    }
    while(gets(wrd))
    {
        sum=0;
        l=strlen(wrd);
        for(i=0;i<l;i++)
        {
            sum=sum+n[wrd[i]];
        }
        if(ar[sum]==0)
        {
            printf("It is a prime word.\n");
        }
        else
        {
            printf("It is not a prime word.\n");
        }
    }
    return 0;
}
