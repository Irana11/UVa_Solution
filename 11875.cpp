#include<stdio.h>

int main()
{
    int t,cs=1,n,ar[11],i,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<n+1;i++)
        {
            scanf("%d",&ar[i]);
        }
        m=(n/2)+1;
        printf("Case %d: %d\n",cs++,ar[m]);
    }
    return 0;
}
