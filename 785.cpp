#include<stdio.h>
#include<string.h>

char ch[50][100],vis[50][100];
char c1,c2;
int i,j,m,n;

void dfs(int i,int j)
{
    if(i<0||j<0||i>=m-1||j>=n)
    return;
    if(ch[i][j]==c1||vis[i][j]==1)
    return;
    vis[i][j]=1;
    ch[i][j]=c2;

    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i-1,j);
}

int main()
{
    int l,max,flg;
     i=0;
      m=0;
        n=0;
        max=0;
    while(gets(ch[i]))
    {

            if(ch[i][0]!='_')
            {

                l=strlen(ch[i]);
               if(max<l)
                {
                    max=l;
                }
                i++;
                continue;
            }
            else
            {
                m=i+1;
                n=max;
            }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(ch[i][j]!=' '&&ch[i][j]!='_'&&ch[i][j]!='\0')
                {
                    c1=ch[i][j];
                    goto next;
                    //break;

                }
            }

        }
        next:
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                vis[i][j]=0;
            }
        }
        for(i=0;i<m;i++)
        {
            l=strlen(ch[i]);
            for(j=0;j<n;j++)
            {
                if(j>l-1)
                {
                    vis[i][j]=1;
                }
            }
        }
        for(i=0;i<m-1;i++)
        {
            for(j=0;j<n;j++)
            {
                if(vis[i][j]==0&&ch[i][j]!=c1&&ch[i][j]!=' '&&ch[i][j]!='\0')
                {
                    c2=ch[i][j];
                    dfs(i,j);
                }
            }

        }
        for(i=0;i<m;i++)
        {
            printf("%s\n",ch[i]);
        }
        i=0;max=0;
    }

    return 0;
}
