#include<stdio.h>

int i,j,k,t,w_cnt,b_cnt;
int w_vis[10][10],b_vis[10][10];
char c,ch[10][10];

void w_dfs(int i,int j)
{
    if(i<0||j<0||j>8||i>8)
    return;
    if(w_vis[i][j]==1||ch[i][j]=='X')
    return;

    w_vis[i][j]=1;

    w_dfs(i+1,j);
    w_dfs(i-1,j);
    w_dfs(i,j+1);
    w_dfs(i,j-1);
}
void b_dfs(int i,int j)
{
    if(i<0||j<0||j>8||i>8)
    return;
    if(b_vis[i][j]==1||ch[i][j]=='O')
    return;

    b_vis[i][j]=1;

    b_dfs(i+1,j);
    b_dfs(i-1,j);
    b_dfs(i,j+1);
    b_dfs(i,j-1);
}

int main()
{
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        for(i=0;i<9;i++)
        {
            gets(ch[i]);
            for(j=0;j<9;j++)
            {
                w_vis[i][j]=0;
                b_vis[i][j]=0;
            }
        }
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                c=ch[i][j];
                if(c=='X'&&b_vis[i][j]==0)
                {
                    b_dfs(i,j);
                }
                else if(c=='O'&&w_vis[i][j]==0)
                {
                    w_dfs(i,j);
                }
            }
        }
        w_cnt=0;
        b_cnt=0;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(w_vis[i][j]==1&&b_vis[i][j]!=1)
                {
                    w_cnt++;
                }
                else if(b_vis[i][j]==1&&w_vis[i][j]!=1)
                {
                    b_cnt++;
                }
            }
        }
        printf("Black %d White %d\n",b_cnt,w_cnt);
    }
    return 0;
}
