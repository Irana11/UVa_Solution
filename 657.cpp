
#include<stdio.h>
int i,j,k,m,n,tmp,t;
int cnt[60],vis[55][55];

char ch[55][55];


void dfs_x(int i,int j)
{
    if(i<0||j<0||i>=m||j>=n)
    return;
    if(ch[i][j]!='X')
    return;

    ch[i][j]='*';

    dfs_x(i+1,j);
    dfs_x(i-1,j);
    dfs_x(i,j-1);
    dfs_x(i,j+1);
}
void dfs_s(int i,int j)
{
    if(i<0||j<0||i>=m||j>=n)
    return;
    if(ch[i][j]=='.'||vis[i][j]==1)
    return;
    if(ch[i][j]=='X')
    {
        cnt[k]++;
        dfs_x(i,j);
    }
    vis[i][j]=1;

    dfs_s(i+1,j);
    dfs_s(i-1,j);
    dfs_s(i,j-1);
    dfs_s(i,j+1);


}
int main()
{
    t=1;
    while((scanf("%d%d",&n,&m))==2&&m!=0&&n!=0)
    {
        getchar();
        for(i=0;i<m;i++)
        {
            scanf("%s",ch[i]);
            for(j=0;j<n;j++)
            {
                vis[i][j]=0;
            }
        }
        for(i=0;i<55;i++)
        {
            cnt[i]=0;
        }
        k=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(ch[i][j]!='.'&&vis[i][j]==0)
                {
                    if(ch[i][j]=='X')
                    {
                        cnt[k]++;
                        dfs_x(i,j);
                    }
                    else
                    {
                         dfs_s(i,j);
                         k++;
                    }

                }

            }
        }
        if(k==0)
        {
            k++;
        }
        for(i=0;i<k;i++)
        {
            for(j=i+1;j<k;j++)
            {
              if(cnt[j]<cnt[i])
              {
                  tmp=cnt[i];
                  cnt[i]=cnt[j];
                  cnt[j]=tmp;
              }
            }
        }
        printf("Throw %d\n",t);
        for(i=0;i<k;i++)
        {
            if(i==0)
            {
                printf("%d",cnt[i]);
            }
            else
            {
                printf(" %d",cnt[i]);
            }
        }
        printf("\n\n");
        t++;
    }
    return 0;
}
