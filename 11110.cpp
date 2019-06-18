#include<stdio.h>
#include<string.h>
#define sz 1000000000
int vis[105][105],n,l,c,cnt2,cnt1,i,j;
char ch[sz],*pch;

void dfs(int i,int j)
{
    if(i<1||j<1||i>n||j>n)
    return;
    if(vis[i][j]!=c||vis[i][j]<0)
    return;

    cnt1++;
    vis[i][j]=-1;
    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i-1,j);
}

int main()
{
    int k,fg,u,v;

    while((scanf("%d",&n))==1&&n!=0)
    {
        getchar();
        cnt2=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                vis[i][j]=0;
            }
        }
        for(i=1;i<n;i++)
        {
            gets(ch);
            l=strlen(ch);
            pch=strtok(ch," ");
            fg=0;
            while(pch!=NULL)
            {
                if(!fg)
                {
                    sscanf(pch,"%d",&u);
                    fg=1;
                }

                else
                {
                    sscanf(pch,"%d",&v);
                    fg=0;
                    vis[u][v]=i;
                }
                pch=strtok(NULL," ");
            }

        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(vis[i][j]>=0)
                {

                    cnt1=0;
                    c=vis[i][j];
                    dfs(i,j);
                    if(cnt1==n)
                    {
                        cnt2++;
                    }
                }
            }

        }
        if(cnt2==n)
        {
            printf("good\n");
        }
        else
        {
             printf("wrong\n");
        }
    }

    return 0;
}
