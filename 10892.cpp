#include<stdio.h>
#include<math.h>
/*#include<algorithm>
using namespace std;*/ //for sort function.
long long ar[1000000];

long long gcd(long long a,long long b)
{
    long long tmp;
    while(b!=0)
    {
        tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}
long long lcm(long long a,long long b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    long long  n,x,y,i,j,rt,cnt,tmp;

    while(scanf("%lld",&n)==1&&n!=0)
    {
        if(n==1)
        {
            printf("1 1\n");
            continue;
        }


        cnt=0;
        rt=sqrt(n);
        j=0;
        for(i=1;i<=rt;i++)
        {
            if(n%i==0)
            {
                ar[j++]=i;
                x=n/i;
                if(x!=i)
                ar[j++]=x;

            }
        }
        y=j;
       // sort(ar,ar+y);
        for(i=0;i<y;i++)
        {
            for(j=i+1;j<y;j++)
            {
                if(ar[i]>ar[j])
                {
                    tmp=ar[i];
                    ar[i]=ar[j];
                    ar[j]=tmp;
                }
            }
        }
        for(i=0;i<y;i++)
        {
            for(j=i+1;j<y;j++)
            {
                x=lcm(ar[i],ar[j]);
                if(x==n)
                cnt++;
            }
        }
        printf("%lld %lld\n",n,cnt+1);
    }
    return 0;
}
