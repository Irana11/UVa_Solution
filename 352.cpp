#include<stdio.h>
#define sz 30
char ch[sz][sz],vis[sz][sz];
char c;
int sq,cnt,cs;

void dfs(int i,int j)
{
    if(i<0||j<0||i>=sq||j>=sq)
    return;
    if(vis[i][j]==1||ch[i][j]=='0')
    return;
    vis[i][j]=1;
    ch[i][j]=c;

    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i+1,j-1);
    dfs(i+1,j+1);
    dfs(i-1,j);
    dfs(i-1,j-1);
    dfs(i-1,j+1);

}

int main()
{
    int i,j;
    cs=1;

    while((scanf("%d",&sq))==1)
    {
        getchar();
        cnt=0;

        for(i=0;i<sq;i++)
        {
            gets(ch[i]);
            for(j=0;j<sq;j++)
            {
                vis[i][j]=0;
            }
        }
        for(i=0;i<sq;i++)
        {
            for(j=0;j<sq;j++)
            {
                if(ch[i][j]!='0'&&ch[i][j]!=' ')
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
        printf("Image number %d contains %d war eagles.\n",cs,cnt);
        cs++;
    }
    return 0;
}
