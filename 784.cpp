
#include<stdio.h>
#include<string.h>
int i,j,t,n,m,max;

char ch[100][100],vis[100][100];
char c,c1;
void dfs(int i,int j)
{
    if(i<0||j<0||i>=m||j>=n)
    return;
    if(vis[i][j]==1||ch[i][j]==c1||ch[i][j]=='_')
    return;
    ch[i][j]=c;
    vis[i][j]=1;

    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i-1,j+1);
    dfs(i-1,j-1);
    dfs(i+1,j+1);
    dfs(i+1,j-1);
}


int main()
{
    scanf("%d",&t);
    getchar();
    c='#';
    while(t--)
    {
        max=0;
        m=0;
        n=0;
        i=0;
        while(1)
        {
            gets(ch[i]);
            if(ch[i][0]=='_')
            {
                m=i+1;
                break;
            }
            n=strlen(ch[i]);
            if(n>max)
            {
                max=n;
            }
            i++;
        }
        n=max;
        c1=ch[0][0];
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                vis[i][j]=0;
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(vis[i][j]==0&&ch[i][j]=='*'&&ch[i][j]!='_'&&ch[i][j]!=c1)
                {
                    dfs(i,j);
                }
            }
        }
        for(i=0;i<m;i++)
        {
            printf("%s\n",ch[i]);
        }



    }
    return 0;
}
