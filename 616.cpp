#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,c,n,flg,rt,i,j;
    while(scanf("%d",&n)==1&&n!=-1)
    {
        if(n==3)
        {
            printf("3 coconuts, 2 people and 1 monkey\n");
            continue;
        }
        flg=0;
        rt=sqrt(n);

        for(i=rt;i>=2;i--)
        {
             a=n;
            for(j=1;j<=i;j++)
            {
                if(a%i==1)
                {
                    a=(a-1)-(a-1)/i;
                }
                else
                {
                    break;
                }
            }
            if(a%i==0&&j-1==i)
            {
                flg=1;
                break;
            }
        }

        if(flg)
        {
            printf("%d coconuts, %d people and 1 monkey\n",n,i);
        }
        else
        {
            printf("%d coconuts, no solution\n",n);
        }
    }
    return 0;
}
