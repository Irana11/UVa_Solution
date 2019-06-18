#include<stdio.h>

int main()
{
    int i,j,t,cs,n,spd,max;

    scanf("%d",&t);

    for(cs=1;cs<=t;cs++)
    {
        max=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&spd);
            if(spd>max)
            {
                max=spd;
            }
        }
        printf("Case %d: %d\n",cs,max);
    }
    return 0;
}
