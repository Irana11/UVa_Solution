#include<stdio.h>
#include<vector>
#define sz 500
using namespace std;

vector<int>vec1[sz];
vector<int>vec2[sz];
int i,j,n,m,k,u,v,x,l;
int vis[sz];

void dfs(int x)
{
    int k;
    int v;
    int l=vec1[x].size();
    for(k=0;k<l;k++)
    {
        v=vec1[x][k];
        if(vis[v]==0)
        {
            vis[v]=1;
            dfs(v);
        }
    }
}

int main()
{
    while((scanf("%d",&n))==1)
    {
        if(n==0)
        break;
        for(i=1;i<=n;i++)
        {
            vec1[i].clear();
            vec2[i].clear();
        }
        while((scanf("%d",&u))==1)
        {
            if(u==0)
            break;
            while((scanf("%d",&v))==1)
            {
                if(v==0)
                break;
                vec1[u].push_back(v);
            }
        }
        scanf("%d",&m);
        for(k=0;k<m;k++)
        {
            for(i=1;i<=n;i++)
            {
                vis[i]=0;
            }
            scanf("%d",&u);
            dfs(u);

            for(i=1;i<=n;i++)
            {
                if(vis[i]==0)
                {
                    vec2[u].push_back(i);
                }
            }
            l=vec2[u].size();
            printf("%d",l);
            for(j=0;j<l;j++)
            {
                printf(" %d",vec2[u][j]);
            }
            printf("\n");
            vec2[u].clear();
        }
    }
    return 0;
}

