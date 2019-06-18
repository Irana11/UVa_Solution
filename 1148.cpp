#include<stdio.h>
#include<queue>
#include<vector>
#define sz 100005
using namespace std;
vector<int>vec[sz];
int vis[sz],cst[sz],i,j,k,l,u,v,t,n,s,d,nc;

void bfs()
{
    int u,v,l,i;
    queue<int>q;
    q.push(s);
    cst[s]=0;
    while(q.empty()==0)
    {
        u=q.front();
        q.pop();
        l=vec[u].size();
        for(i=0;i<l;i++)
        {
            v=vec[u][i];
            if(vis[v]==0)
            {
                q.push(v);
                vis[v]=1;
                cst[v]=cst[u]+1;
            }
        }
    }
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       for(j=0;j<n;j++)
       {
           scanf("%d%d",&u,&nc);
           while(nc--)
           {
               scanf("%d",&v);
               vec[u].push_back(v);
               vec[v].push_back(u);
           }
           vis[u]=0;
       }
       scanf("%d%d",&s,&d);
       bfs();
       printf("%d %d %d\n",s,d,cst[d]-1);
       for(i=0;i<n;i++)
       vec[i].clear();
       if(t)
       {
           printf("\n");
       }
    }
    return 0;
}
