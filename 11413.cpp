#include<stdio.h>
using namespace std;
int v,c,v_ar[1010],i,low,high,mid,sum,cnt,ans;

bool trycapacity(int mx)
{

    sum=0;
    cnt=0;
    for(i=0;i<v;i++)
    {
        if(v_ar[i]>mx)
        return 0;
        if(sum+v_ar[i]>mx)
        sum=0;
        if(sum==0)
        cnt++;
        if(cnt>c)
        return 0;
        sum+=v_ar[i];
    }
    return 1;
}

int main()
{
    while(scanf("%d%d",&v,&c)==2)
    {
        for(i=0;i<v;i++)
        {
            scanf("%d",&v_ar[i]);
            high+=v_ar[i];
        }
        high++;
        low=1;
        while(low<=high)
        {
            mid=(high+low)/2;
            if(trycapacity(mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
