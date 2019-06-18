#include<stdio.h>
#define sz 10000001
bool cnt[sz];
int i,j,d,cs,t,n,b_p;

int main()
{

    scanf("%d",&cs);
    while(cs--)
    {
        scanf("%d%d",&d,&t);
        n=(1<<d)-1;

        for(i=1;i<=n;i++)
        {
            cnt[i]=0;
        }
        for(i=0;i<t;i++)
        {
            j=1;
            while(j<=n)
            {
                if(cnt[j]==0)
                {
                   cnt[j]=1;
                   j*=2;
                }
                else
                {
                   cnt[j]=0;
                   j=(j*2)+1;
                }
                if(j>n)
                {

                    j/=2;
                    printf("%d\n", j);
                    break;
                }
            }
        }
        printf("%d\n",j);
    }
    int mns;
    scanf("%d",&mns);
    return 0;
}
