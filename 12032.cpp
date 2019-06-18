#include<stdio.h>
using namespace std;
int i,k,n,t,cs,mid,low,high,ans,sum;
int ar[1000000];

bool tryk(int k)
{
    for(i=1;i<=n;i++)
    {
        if(ar[i]-ar[i-1]>k)
        return 0;
        if(ar[i]-ar[i-1]==k)
        k--;
    }
    return 1;
}

int main()
{
    cs=1;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ar[i]);
            sum+=ar[i];
        }
        ar[0]=0;
        low=1;
        high=10000000;
        ans=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(tryk(mid))
            {
               // printf("%d\n",mid);
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}

