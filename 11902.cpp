#include<stdio.h>
#include<vector>
using namespace std;

vector<int>vec[110];
vector<int>store;

int ar[110][110],vis[110],i,j,l1,l,k,n,t,cs,now,cnt,x,y;
void dfs_r(int x)
{
    int i,j,u,l;
    vis[x]=1;
    l=vec[x].size();
    for(i=0;i<l;i++)
    {
        u=vec[x][i];
        if(vis[u]==0)
        {
            store.push_back(u);
            vis[u]=1;
            dfs_r(u);
        }
    }
}
void dfs(int x)
{
    int l,i,u;
   vis[x]=1;
   l=vec[x].size();
   for(i=0;i<l;i++)
   {
       u=vec[x][i];
       if(vis[u]==0&&u!=now)
       {
           cnt++;
           vis[u]=1;
           dfs(u);
       }
   }

}
int main()
{
    cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            vis[i]=0;
            vec[i].clear();
            store.clear();

        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&ar[i][j]);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(ar[i][j]==1)
                {
                    vec[i].push_back(j);
                    ar[i][j]=0;
                }
            }
        }
        ar[0][0]=1;
        dfs_r(0);
        l1=store.size();

        for(i=0;i<l1;i++)
        {
            now=store[i];
            ar[0][now]=1;
            ar[now][now]=1;
            for(j=0;j<l1;j++)
            {
                vis[store[j]]=0;
            }
            cnt=0;
            dfs(0);
            if(cnt==l1-1)
            {
                continue;
            }
            for(j=0;j<l1;j++)
            {
                x=store[j];
                if(vis[x]==0)
                {
                    ar[now][x]=1;
                }
            }
        }
        printf("Case %d:\n",cs);
        cs++;
        i=0;
        for(x=1;x<=(2*n)+1;x++)
        {
            if(x%2==1)
            {
                printf("+");
                for(y=2;y<=2*n;y++)
                {
                    printf("-");
                }
                printf("+\n");
            }
            else
            {
                j=0;
                for(y=1;y<=2*n+1;y++)
                {
                    if(y%2==0)
                    {
                        if(ar[i][j]==1)
                        {
                             printf("Y");
                        }
                        else
                        {
                            printf("N");
                        }
                        j++;
                    }
                    else
                    {
                        printf("|");
                    }
                }
                i++;
                printf("\n");
            }

        }
       /* for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d ",ar[i][j]);
            }
            printf("\n");
        }*/

    }
    return 0;
}
