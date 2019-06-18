#include<stdio.h>

int i,j,k;
int ara[1010],s[1010],p[1010],p1[1010];
void sieve()
{
    p[k]=1;
    k=1;
    for(i=2;i<1010;i++)
    {
        ara[i]=1;
    }
    for(i=2;i<1010;i++)
    {
        if(ara[i]==1)
        {
            for(j=2;i*j<1010;j++)
            {
                ara[i*j]=0;
            }
            p[k]=i;
            k++;
        }
    }

}

int main()
{
    int N,C,n,d;
    sieve();
    while((scanf("%d%d",&N,&C))==2)
    {
        printf("%d %d:",N,C);
        i=0;
        j=0;
        while(p[i]<=N&&i<k)
        {
            p1[j]=p[i];
            j++;
            i++;
        }
        if(j%2==0)
        {
            n=C*2;
        }
        else
        {
            n=(C*2)-1;
        }
        if(n>j)
        {
           d=0;
           n=j;
        }
        else
        {
            d=j-n;
            d=d/2;
        }

        for(i=d,j=0;i<(d+n);i++,j++)
        {
            s[j]=p1[i];
            printf(" %d",s[j]);
        }
        printf("\n\n");
    }
    return 0;
}
