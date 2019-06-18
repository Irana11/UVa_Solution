#include<stdio.h>

int main()
{
    int i,cnt,t,cs,n,sum;
    int ar[1005];
    double a;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        sum=0;
        cnt=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            sum=sum+ar[i];
        }
        a=sum/n;
        for(i=0;i<n;i++)
        {
            if(ar[i]>a)
            {
                cnt++;
            }
        }
        a=cnt*100;
        a/=n;
        printf("%0.3lf%%\n",a);

    }
}
