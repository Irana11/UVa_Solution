#include<stdio.h>


int main()
{
    char ch[15][15];
    int vis[15][15];
    int i,j,l,r,c,s,loop,cnt;
    while(scanf("%d%d%d",&r,&c,&s)==3)
    {
        if(r==0&&c==0&&s==0)
        break;
        for(i=0;i<r;i++)
        {
            scanf("%s",ch[i]);
            for(j=0;j<c;j++)
            {
                vis[i][j]=0;
            }
        }
        i=0;
        j=s-1;
        l=0;
        cnt=0;
        loop=0;
        while(1)
        {
            if(vis[i][j]==0)  cnt++;

            vis[i][j]++;
           // printf("%c\n",ch[i][j]);
            if(vis[i][j]==3)
            {
               loop=1;
                break;
            }
            if(ch[i][j]=='W')j--;
            else if(ch[i][j]=='E') j++;
            else if(ch[i][j]=='S') i++;
            else i--;
            if(i<0||j<0||i>=r||j>=c)
            break;
        }
        if(loop==0)
        {
            printf("%d step(s) to exit\n",cnt);
        }
        else
        {
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    if(vis[i][j]>1)
                    {
                       l++;
                    }
                }
            }
            printf("%d step(s) before a loop of %d step(s)\n",(cnt-l),l);
        }
    }
    return 0;
}
