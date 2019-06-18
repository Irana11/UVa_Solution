#include<stdio.h>
#include<math.h>
#define sz 500005
//#define sz 10

int main()
{
    int ar[sz],i,j,n,k,x;
    i=1;
    j=2;
    while(j<sz)
    {
        ar[j]=j;
        i++;
        j=pow(2,i);
    }
    ar[0]=0;
    ar[1]=1;
    for(i=3; i<sz; i++)
    {
        n=2;
        while(ar[i]!=i&&i<sz)
        {
            ar[i]=n;
            n+=2;
            i++;
        }
    }

    while(scanf("%d",&n)==1&&n!=0)
    {
        printf("%d\n",ar[n]);
    }

    return 0;
}
