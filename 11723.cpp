#include<stdio.h>

int main()
{
    int r,n,x,d,cs=1,mx;
    while(scanf("%d%d",&r,&n)==2)
    {
        if(r==0&&n==0)
        break;
        mx=n+n*26;
        x=r-n;
      //  d=x/n;
        if(r>mx)
        {
            printf("Case %d: impossible\n",cs++);
        }
        else if(x<0)
        {
            printf("Case %d: 0\n",cs++);
        }
        else
        {
            if(x%n==0)
                printf("Case %d: %d\n",cs++,x/n);
            else
                printf("Case %d: %d\n",cs++,x/n+1);

        }
    }
    return 0;
}
