#include<stdio.h>
#define sz 110
#include<vector>
using namespace std;

vector<int>vec[sz];
int i,j,k,u,v,n,x,t,tmp,mx;
int vis[sz],cnt[sz];

void dfs(int x)
{
    int j;
    int l=vec[x].size();
    vis[x]=1;
    for(j=0;j<l;j++)
    {
        v=vec[x][j];
        if(vis[v]==0)
        {
            cnt[k]++;
            dfs(v);
        }
    }

}
int main()
{
    while((scanf("%d",&n))==1&&n!=0)
    {
        for(i=1;i<=n;i++)
        {
            vec[i].clear();
            vis[i]=0;
            cnt[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&t);
            for(j=1;j<=t;j++)
            {
                scanf("%d",&u);
                vec[i].push_back(u);
            }
        }
        for(i=1;i<=n;i++)
        {
            k=i;
            dfs(i);
            for(j=1;j<=n;j++)
            {
                vis[j]=0;
            }
        }
        mx=0;
        for(i=1;i<=n;i++)
        {
            if(cnt[i]>mx)
            {
                mx=cnt[i];
                tmp=i;
            }
        }
        printf("%d\n",tmp);

    }
    return 0;
}
