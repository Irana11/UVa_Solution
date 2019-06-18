#include<stdio.h>
#define sz 3010

int main()
{
    int ar[sz],cnt[sz],i,j,k,flg,n,d;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            cnt[i]=0;
        }
        for(i=0;i<n-1;i++)
        {
            d=ar[i]-ar[i+1];
            if(d<0)
                d*=-1;
            cnt[d]++;
        }
        flg=0;
        for(i=1;i<n;i++)
        {
            if(cnt[i]!=1)
                flg=1;
        }
        if(flg==0)
        {
            printf("Jolly\n");
        }
        else
           printf("Not jolly\n");
    }
    return 0;

}
