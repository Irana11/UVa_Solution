#include<stdio.h>

int main()
{
    int n,q,t,ar[50015],tmp[50005],i,j,h,l,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
        tmp[0]=ar[0];
    }
    for(i=0,j=1;i<n-1;i++)
    {
        if(ar[i+1]!=ar[i])
        {
             tmp[j]=ar[i+1];
             j++;
        }
    }
    n=j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&q);
        l=0;
        h=n-1;
        while(l<=h)
        {
             m=(l+h)/2;
            if(tmp[m]==q)
                break;
            if(tmp[m]<q)
                l=m+1;
            else
                h=m-1;
        }
       if(tmp[m]==q)
       {
          if(m-1<0)
                printf("X ");
          else
            printf("%d ",tmp[m-1]);
          if(m+1==n)
            printf("X");
          else
            printf("%d",tmp[m+1]);
       }
       else
       {
           if(tmp[m]>q)
           {
                if(m-1<0)
                    printf("X ");
                else
                    printf("%d ",tmp[m-1]);
                printf("%d",tmp[m]);
           }
           else
           {
               printf("%d ",tmp[m]);
               if(m+1==n)
                printf("X");
               else
                printf("%d",tmp[m+1]);
           }
       }
       printf("\n");
    }
    return 0;
}

