#include<stdio.h>
#define sz 105
int m,n,vis[sz][sz],cnt_s,cnt_r;
char c,ch[sz][sz];

void dfs(int i,int j)
{
    if(i<0||j<0||i>=m||j>=n)
    return;
    if(ch[i][j]=='.'||vis[i][j]==1)
    return;
    c=ch[i][j];
    vis[i][j]=1;
    cnt_s++;

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
    int i,j,cnt_r;
    while((scanf("%d%d",&m,&n))==2&&(m!=0)&&(n!=0))
    {
        getchar();

        for(i=0;i<m;i++)
        {
            gets(ch[i]);
            for(j=0;j<n;j++)
            {
                vis[i][j]=0;
            }
        }

        cnt_r=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cnt_s=0;
                if(ch[i][j]!=' '&&ch[i][j]!='.')
                {
                    c=ch[i][j];
                    dfs(i,j);
                    if(cnt_s==1)
                    {
                        cnt_r++;
                    }
                }
            }
        }
        printf("%d\n",cnt_r);
    }
    return 0;
}
