#include<stdio.h>
#include<queue>
#include<vector>
#include<map>
#define mx 99999999
using namespace std;
vector<int>vec[50];
map<int,int>mp;
queue<int>q;
int level[50],i,j,ttl,u,v,cs=1,x,t,node,l,s,cnt;

void bfs()
{
    int i,l,j,u,v;
    q.push(s);
    level[s]=0;
    while(q.empty()==0)
    {
        u=q.front();
        q.pop();
        l=vec[u].size();
        for(i=0;i<l;i++)
        {
            v=vec[u][i];
            if(level[v]==mx)
            {
                q.push(v);
                level[v]=level[u]+1;
            }
        }
    }
}
int main()
{
    while(scanf("%d",&t)==1&&t!=0)
    {
        node=1;
        while(t--)
        {
            scanf("%d%d",&u,&v);
            if(mp[u]==0)
            {
                mp[u]=node++;
            }
            if(mp[v]==0)
            {
                mp[v]=node++;
            }
            u=mp[u];
            v=mp[v];
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        while(scanf("%d%d",&u,&ttl)==2)
        {
            if(u==0&&ttl==0)
            break;
            for(i=1;i<node;i++)
            {
                level[i]=mx;
            }
            cnt=0;
            s=mp[u];
            bfs();
            for(i=1;i<node;i++)
            {
                if(level[i]>ttl)
                {
                    cnt++;
                }
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cs,cnt,u,ttl);
            cs++;
        }
        for(i=0;i<node;i++)
        {
            vec[i].clear();
        }
        mp.clear();
    }
    return 0;
}
