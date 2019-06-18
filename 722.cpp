#include<stdio.h>
#include<string.h>

int i,j,l,cnt,k,t,m,n,r,c;
int vis[100][100];
char ch[100][100];

void dfs(int i,int j)
{
    if(i<0||j<0||i>=r||j>=c)
    return;
    if(vis[i][j]==1||ch[i][j]=='1')
    return;

    vis[i][j]=1;
    cnt++;

    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&i,&j);
        m=i-1;
        n=j-1;
        getchar();

        r=0;
        while(gets(ch[r]))
        {
            if(strcmp(ch[r],"")==0)
            {
                break;
            }
            r++;
        }
        c=strlen(ch[r-1]);
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                vis[i][j]=0;
            }
        }

        cnt=0;
        dfs(m,n);
        printf("%d\n",cnt);

        if(t)
        {
            printf("\n");
        }
    }
    return 0;

}


