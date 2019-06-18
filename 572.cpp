#include<stdio.h>

char ch[105][105],vis[105][105];
char c;
int m,n;

void dfs(int i,int j)
{
    if(i<0||j<0||i>=m||j>=n)
    return;
    if(vis[i][j]==1||ch[i][j]=='*')
    return;
    ch[i][j]=c;
    vis[i][j]=1;

    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i+1,j+1);
    dfs(i+1,j-1);
    dfs(i-1,j+1);
    dfs(i-1,j-1);

}

int main()
{
    int i,j,cnt;
    while((scanf("%d%d",&m,&n))==2&&(m!=0)&&(n!=0))
    {
        cnt=0;
        getchar();
        for(i=0;i<m;i++)
        {
            gets(ch[i]);
            for(j=0;j<n;j++)
            {
                vis[i][j]=0;
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(ch[i][j]!=' '&&ch[i][j]!='*')
                {
                    c=ch[i][j];

                    if(vis[i][j]!=1)
                    {
                        cnt++;
                    }
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
