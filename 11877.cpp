#include<stdio.h>

int main()
{
    int e,n,cnt;

    while(scanf("%d",&n)==1&&n!=0)
    {
        cnt=0;
        while(n>=3)
        {
            n=n-3;
            cnt++;
            n+=1;
        }
        if(n==2)
        {
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
