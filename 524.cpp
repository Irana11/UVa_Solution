#include<stdio.h>
#define sz 30
int ar[sz],take[sz],res[sz];
int i,j,cnt,n,t,cs=1;
bool is_prm[sz];

void func()
{
    long i;
    int sum;
    if(j==n)
    {
        for(i=0;i<n-1;i++)
            printf("%d ",res[i]);
        printf("%d\n",res[n-1]);
    }
    else
    {
        for(i=1;i<n;i++)
        {
            if(take[i]==0)
            {
                if(j==(n-1))
                {
                    sum=res[0]+ar[i];
                    if(is_prm[sum]!=1)
                        return;
                }
                sum=res[j-1]+ar[i];
                if(is_prm[sum]==1)
                {
                    take[i]=1;
                    res[j++]=ar[i];
                    func();
                    take[i]=0;
                    j--;
                }
            }
        }
    }
}
int main()
{
   int flag=0;
   is_prm[2]=is_prm[3]=is_prm[5]=is_prm[7]=is_prm[11]=is_prm[13]=is_prm[17]=is_prm[19]=is_prm[23]=is_prm[29]=is_prm[31]=1;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            ar[i]=i+1;
        if(flag)
            printf("\n");
        flag=1;
        printf("Case %d:\n",cs++);
        res[0]=1;
        j=1;
        func();
    }
    return 0;
}
