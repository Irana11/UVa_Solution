#include<stdio.h>

int main()
{
    int t,i,n,r,cnt;
    t=1;
    while((scanf("%d",&n))==1&&n>0)
    {
        r=1;
        cnt=0;
        while(r<n)
        {
             r=2*r;
             cnt++;
        }
            printf("Case %d: %d\n",t,cnt);
            t++;


    }
    return 0;

}
