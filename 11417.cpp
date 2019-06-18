#include<stdio.h>

int gcd(int a,int b)
{
    int tmp=0;
    while(b!=0)
    {
        tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}

int main()
{
    int i,j,n,g;
    while((scanf("%d",&n))==1&&n!=0)
    {
        g=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                g+=gcd(i,j);
            }
        }
        printf("%d\n",g);
    }
    return 0;
}
