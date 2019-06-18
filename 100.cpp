#include<stdio.h>

int main()
{
    int i,j,n1,n2,cnt,tmp,max,flg;
    while((scanf("%d%d",&n1,&n2))==2)
    {
        flg=0;
        if(n1>n2)
        {
            tmp=n2;
            n2=n1;
            n1=tmp;
            flg=1;
        }

        max=0;
        for(j=n1;j<=n2;j++)
        {
            cnt=1;
            i=j;
            while(i!=1)
            {
                if(i%2==0)
                {
                    i=i/2;
                    cnt++;
                }
                else
                {
                    i=3*i+1;
                    cnt++;
                }

            }
            if(max<cnt)
            {
                max=cnt;
            }
        }
        if(flg==1)
        {
             printf("%d %d %d\n",n2,n1,max);
        }
        else
        {
             printf("%d %d %d\n",n1,n2,max);
        }

    }
    return 0;
}
