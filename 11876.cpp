
#include<stdio.h>
#include<math.h>
#define sz 65000

int main()
{
    int t,i,j,cs=1,rt,cnt,start,finish,low,high,mid,ar[sz],x,y;
    ar[0]=1;
    for(i=1;i<sz;i++)
    {
        cnt=0;
        rt=sqrt(ar[i-1]);
        for(j=1;j<=rt;j++)
        {
           if(ar[i-1]%j==0)
           {
               if(j*j==ar[i-1])
                cnt++;
               else
                cnt+=2;
           }
        }
        ar[i]=ar[i-1]+cnt;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&start,&finish);
        cnt=0;
        low=0;
        high=sz-1;
        while(1)
        {
            if(ar[low]>start)
            {
                y=low;
                break;
            }
            mid=(low+high)/2;

            if(ar[mid]==start)
              {
                 y=mid;
                 break;
              }
            if(ar[mid]>start)
                high=mid-1;
            else
               low=mid+1;
        }
        low=0;
        high=sz-1;
        while(1)
        {
            if(ar[high]<finish)
            {
                x=high;
                break;
            }
            mid=(low+high)/2;
            if(ar[mid]==finish)
            {
                x=mid;
                break;
            }
            if(ar[mid]>finish)
                high=mid-1;
            else
                low=mid+1;
        }
        cnt=x-y+1;
        printf("Case %d: %d\n",cs++,cnt);
    }
    return 0;
}



