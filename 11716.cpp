#include<stdio.h>
#include<string.h>
#include<math.h>

char st[10005],ch[10005];

int main()
{
    int i,j,cnt,rt,l,t,y;
    scanf("%d",&t);
    gets(st);
    for(y=1;y<=t;y++)
    {
        for(i=0;i<10005;i++)
        {
            ch[i]=0;
        }

        gets(st);
        l=strlen(st);
        rt=sqrt(l);
        if(rt*rt!=l)
        {
            printf("INVALID\n");
        }
        else
        {
            for(i=0;i<rt;i++)
            {
                cnt=0;
                j=i;
                while(cnt<rt)
                {
                    printf("%c",st[j]);
                    j=j+rt;
                    cnt++;
                }
            }
            printf("\n");

        }


    }
    return 0;
}
