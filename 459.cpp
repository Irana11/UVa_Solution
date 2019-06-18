
#include<stdio.h>
#include<string.h>
int mat[30][30],a[100];
int i,j,n;
int vis[30];

void dfs(int j)
{
    for(int k=1; k<=n; k++)
    {
        if(mat[j][k]==1)
        {
            mat[j][k]=0;
            mat[k][j]=0;
            vis[k]=1;
            dfs(k);
        }
    }
}

int main()
{
    int cnt,t,n1,n2,flg,l;
    char c;
    char s1[2],s2[100];

    scanf("%d",&t);
    getchar();
    getchar();
    while(t--)
    {
        cnt=0;
        gets(s1);
        n=s1[0]-64;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                mat[i][j]=0;
            }
            vis[i]=0;
        }
        while(gets(s2))
        {
            if(strcmp(s2,"")==0)
            {
                break;
            }
            n1=s2[0]-64;
            n2=s2[1]-64;
            mat[n1][n2]=mat[n2][n1]=1;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1; j<=n; j++)
            {
                if(mat[i][j]==1&&vis[i]==0)
                {
                    vis[i]=1;
                    dfs(i);
                    cnt++;
                }
            }
        }
        for(i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                cnt++;
            }
        }
        printf("%d\n",cnt);
        if(t>0)
        {
            printf("\n");
        }
    }
    return 0;
}
