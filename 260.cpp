#include<stdio.h>
int i,j,k,n,t,m;
int vis[300][300];
char ch[300][300];
char c;

void dfs(int i,int j)
{
    if(i<0||j<0||i>=n||j>=n)
    return;
    if(vis[i][j]!=0||ch[i][j]!=c)
    return;

    if(i+1>m)
    {
        m++;
    }
    vis[i][j]=1;
    dfs(i,j-1);
    dfs(i,j+1);
    dfs(i+1,j);
    dfs(i+1,j+1);
}

int main()
{
    c='b';
    t=1;
    while(scanf("%d",&n)==1&&n!=0)
    {
        m=1;
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
            k=1;
            for(j=0;j<n;j++)
            {
                if(ch[i][j]==c&&m!=n)
                {
                    if(i+1>k)
                    {
                        k++;
                        break;
                    }
                    else
                    {
                        m=1;
                        dfs(i,j);
                    }
                }
            }
        }
        if(m==n)
        {
            printf("%d B\n",t);
        }
        else
        {
            printf("%d W\n",t);
        }
        t++;
    }
    return 0;
}
