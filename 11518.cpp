
#include<stdio.h>
#include<vector>
using namespace std;
vector<int>vec[10010];
int i,j,l,cnt,u,v;
int vis[10010];


void dfs(int x)
{
    int i;
    int l=vec[x].size();
    vis[x]=1;
    for(i=0;i<l;i++)
    {
        u=vec[x][i];
        if(vis[u]==0)
        {
            cnt++;
            dfs(u);
        }

    }
}

int main()
{
    int t,n,m,l,z,sz;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&l);
        for(i=1;i<=n;i++)
        {
            vec[i].clear();
            vis[i]=0;
        }
        while(m--)
        {
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);

        }
        cnt=0;
        while(l--)
        {
            scanf("%d",&z);
            if(vis[z]==0)
            {
                cnt++;
                dfs(z);
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
