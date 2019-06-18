#include<stdio.h>
#include<vector>
#define sz 50010

using namespace std;
vector<int>vec[sz];
int cnt[sz];
bool vis[sz],vis1[sz];
int i,j,k,u,v,t,cs,mx,n,x,sum;

void dfs(int x)
{
    sum=0;
    int j,v;

    v=vec[x][0];
    if(vis[v]==0||vis1[x]==0)
    {
        if(vis1[x]!=1)
        {
            cnt[x]=cnt[x-1]+1;
            vis1[x]=1;
        }
        else
        {
            cnt[x]=1;
        }
        vis[v]=1;
        dfs(v);
    }
}

int main()
{
    int cs=1;
    scanf("%d",&t);
    while(t--)
    {
        mx=0;
        cnt[0]=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            vec[i].clear();
            cnt[i]=0;
            vis[i]=0;
            vis1[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
        }
        k=50001;
        for(i=1;i<=n;i++)
        {
            u=i;
            if(vis1[i]==0)
            {
                dfs(i);
            }
        }
        j=0;
        while(n--)
        {
            if(cnt[j]>mx)
            {
                mx=cnt[j];
                k=j+1;
            }
            j++;
        }
        printf("Case %d: %d\n",cs,k);
        cs++;
    }
    return 0;
}

