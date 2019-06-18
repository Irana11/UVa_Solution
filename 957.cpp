#include<stdio.h>

int main()
{
    int yr,p,ar[100005],i,low,high,mid,indx,q,x,y,cnt,mx,bg,en,j;

    while(scanf("%d",&yr)==1)
    {
        scanf("%d",&p);
        i=0;
        for(;i<p;)
        {
            scanf("%d",&ar[i++]);
        }
        mx=0;
        for(i=0;i<p;i++)
        {
            x=ar[i];
            y=x+yr-1;
            low=0;
            high=p-1;
            cnt=0;
            indx=-1;
            j=i;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(ar[mid]==y)
                {
                    indx=mid;
                    low=mid+1;
                }
                else if(ar[mid]>y)
                    high=mid-1;
                else
                    low=mid+1;
            }
            if(indx==-1)
                indx=mid-1;
           cnt=indx-j+1;
           if(cnt>mx)
            {
                mx=cnt;
                bg=x;
                en=ar[indx];
            }
        }
        printf("%d %d %d\n",mx,bg,en);
    }
    return 0;
}
