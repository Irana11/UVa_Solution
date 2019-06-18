#include<stdio.h>
int t,n,cs,i,j,cnt,flg;
int vis[105][105];
char ch[105][105];
char c;

void dfs(int i,int j)
{
    if(i<0||j<0||i>=n||j>=n)
    return;
    if(vis[i][j]==1||ch[i][j]=='.')
    return;

    if(ch[i][j]=='x'&&flg!=1)
    {
        cnt++;
        flg=1;
    }
    vis[i][j]=1;

    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}

int main()
{
    scanf("%d",&t);
    cs=1;
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        cnt=0;

        for(i=0;i<n;i++)
        {
            scanf("%s",ch[i]);
            for(j=0;j<n;j++)
            {
                vis[i][j]=0;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if((ch[i][j]=='@'||ch[i][j]=='x')&&vis[i][j]==0)
                {
                    flg=0;
                    dfs(i,j);
                }
            }
        }
        printf("Case %d: %d\n",cs,cnt);
        cs++;
    }
    return 0;
}
