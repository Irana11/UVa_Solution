#include<stdio.h>
#include<string.h>

int i,j,k,max,cnt,t,m,n,l;
int vis[30][30];
char ch[30][30],s[5];
char c;

void dfs(int i,int j)
{
    if(i<0||j<0||i>=m||j>=n)
    return;
    if(vis[i][j]!=0||ch[i][j]!='1')
    return;

    cnt++;
    vis[i][j]=1;
    ch[i][j]='0';

    dfs(i,j-1);
    dfs(i,j+1);
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i+1,j-1);
    dfs(i+1,j+1);
    dfs(i-1,j-1);
    dfs(i-1,j+1);
}
int main()
{
    scanf("%d",&t);
    getchar();
    getchar();

    while(t--)
    {
        max=0;
        i=0;
        j=0;
        while(gets(ch[i]))
        {
            if(strcmp(ch[i],"")==0)
            {
                break;
            }
            i++;
        }
        m=i;
        n=strlen(ch[i-1]);
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
                if(ch[i][j]=='1'&&vis[i][j]==0)
               {
                    cnt=0;
                   dfs(i,j);
                   if(cnt>max)
                   {
                       max=cnt;
                   }
               }
            }
        }
        printf("%d\n",max);
        if(t)
        {
            printf("\n");
        }
    }
    return 0;
}
