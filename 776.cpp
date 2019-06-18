#include<stdio.h>
#include<string.h>

int vis[1010][1010],cnt[1010][1010],chck[1010],i,j,k,max,r,l,n;
char ch[1010][1010],c;

void dfs(int i,int j)
{
    if(i<0||j<0||i>=r||j>=l)
    return;
    if(vis[i][j]==1||ch[i][j]!=c)
    return;

    vis[i][j]=1;
    cnt[i][j]=n;

    dfs(i,j+2);
    dfs(i,j-2);
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i-1,j-2);
    dfs(i-1,j+2);
    dfs(i+1,j-2);
    dfs(i+1,j+2);
}

int main()
{
    while(gets(ch[0]))
    {
        l=strlen(ch[0]);
        r=1;
        while(gets(ch[r]))
        {
            if(ch[r][0]=='%')
            {
                break;
            }
            r++;
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<l;j++)
            {
                vis[i][j]=0;
                cnt[i][j]=0;
                chck[j]=0;
            }
        }
        n=1;
        for(i=0;i<r;i++)
        {
            for(j=0;j<l;j+=2)
            {
                if(vis[i][j]==0)
                {
                    c=ch[i][j];
                    dfs(i,j);
                    n++;
                }
            }
        }
        for(j=0;j<l;j++)
        {
            max=0;
            for(i=0;i<r;i++)
            {
                if(cnt[i][j]>max)
                {
                    max=cnt[i][j];
                }
            }
            while(max)
            {
                chck[j]++;
                max/=10;
            }
        }
        for(i=0;i<r;i++)
        {
            printf("%*d",chck[0],cnt[i][0]);
            for(j=2;j<l;j++)
            {
                if(ch[i][j]!=32)
                {
                    printf(" %*d",chck[j],cnt[i][j]);
                }
            }
            printf("\n");
        }
        printf("%%\n");
    }
    return 0;
}
